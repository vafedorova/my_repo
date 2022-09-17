#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
  string questions_file_name = "questions.txt";
  ifstream fin(questions_file_name);
  string file_name = "results.txt";
  ofstream fout(file_name, ios::app);
  while (!fin.eof()) {
    string question;
    getline(fin, question);
    cout << question;
    string answer;
    getline(cin, answer);
    fout << answer << " ";
  }
  fout << endl;
  fout.close();
  fin.close();
}