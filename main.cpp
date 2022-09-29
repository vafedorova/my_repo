#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
#include <stdlib.h>

using namespace std;

string file_name = "results.txt";
string question_file_name = "questions.txt";
const string WHITESPACE = " \n\r\t\f\v";

void poll();
void get_data(int w, int h);
void update_questions();
string ltrim(const string &s);
string rtrim(const string &s);
string trim(const string &s);
string str(int a);

int main() {
    cout << "Conduct a survey (1), display saved results (2) or update questions (3): ";
    string choice;
    getline(cin, choice);
    if (choice == "1") {
        poll();
    }
    else if (choice == "2") {
        get_data(15, 100);
    }
    else if (choice == "3") {
        update_questions();
    }
    else {
        cout << "Wrong input";
    }
}

void poll() {
    ofstream fout(file_name, ios::app);
    ifstream quest(question_file_name);
    if (!quest.is_open()) {
        cout << "No question file";
        return;
    }
    while (!quest.eof()) {
        string question, ans;
        getline(quest,question);
        question = trim(question);
        if (question == "")
            continue;
        cout << question << ":\n";
        getline(cin, ans);
        ans = trim(ans);
        fout << ans << "\n";
    }
    cout << "Thanks for participating in the survey";
    fout.close();
}

void get_data(int w, int h) {
    ifstream quest(question_file_name);
    if (!quest.is_open()) {
        cout << "No question file";
        return;
    }
    string q;
    int cnt = 0;
    while (!quest.eof()) {getline(quest, q); cnt++;}
    cout << setiosflags(ios::left);
    for (int i = 1; i < cnt; i++)
        cout << setw(w) << "Question" + str(i);
    cout << endl;
    int count = 0;
    map<string, int> answers;
    ifstream fin(file_name);
    while (!fin.eof()) {
        cout << setiosflags(ios::left);
        for (int i = 0; i < cnt; i++) {
            string ans;
            getline(fin, ans);
            ans = trim(ans);
            answers[ans]++;
            cout << setw(w) << ans;
        }
        count++;
        if (cnt > h)
            break;
        cout << endl;
    }
    fin.close();
    count--;
    string max_ans = "def";
    int max_count = -1;
    for (auto kvp: answers) {
        string f = kvp.first;
        int c = kvp.second;
        if (f == "")
            continue;
        if (max_count < c) {
            max_ans = f;
            max_count = c;
        }
    }
    cout << "Answers count: " << count << " The most beloved answer: " << max_ans << endl;
}

void update_questions() {
    ofstream quest(question_file_name);
    ofstream res_cl(file_name);
    string q;
    getline(cin, q);
    q = trim(q);
    while (q != "end") {
        quest << q << endl;
        getline(cin, q);
        q = trim(q);
    }
    quest.close();
    res_cl.close();
}

string ltrim(const string &s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s) {
    return rtrim(ltrim(s));
}

string str(int a){
    char intStr[10];
    itoa(a, intStr, 10);
    return string(intStr);
}
