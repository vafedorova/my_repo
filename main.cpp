#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <unordered_map>
using namespace std;

int main() {
  cout << "Провести опрос (1) или вывести сохраненные результаты (2): ";
  string choice;
  cin >> choice;
  string file_name = "results.txt";
  ofstream fout(file_name, ios::app);
  if (choice == "1") {
    cout << "Введите имя: ";
    string name;
    cin >> name;
    cout << "Введите фамилию: ";
    string surname;
    cin >> surname;
    cout << "Введите любимый фильм: ";
    string film;
    getline(cin, film);
    getline(cin, film);
    fout << name << " " << surname << " " << film << endl;
    fout.close();
  }
  else if (choice == "2") {
    cout << setiosflags(ios::left) << setw(20) << "Name" << setw(20) << "Surname" << setw(20) << "Film" << endl;
    int count = 0;
    unordered_map<string, int> film_counts;
    ifstream fin(file_name);
    while (!fin.eof()) {
      string line;
      getline(fin, line);
      count++;
      int pos = line.find(" ");
      string name = line.substr(0, pos);
      line.erase(0, pos + 1);
      pos = line.find(" ");
      string surname = line.substr(0, pos);
      line.erase(0, pos + 1);
      string film = line;
      if (film_counts.find(film) == film_counts.end()) {
        film_counts.insert({film, 1});
      }
      else {
        film_counts[film]++;
      }
      cout << setiosflags(ios::left) << setw(20) << name << setw(20) << surname << setw(20) << film << endl;
    }
    fin.close();
    count--;
    string film_max;
    int max_count = 0;
    for (auto &kvp: film_counts) {
      string f = kvp.first;
      int c = kvp.second;
      if (film_max == "" || max_count < c) {
        film_max = f;
        max_count = c;
      }
    }
    cout << "Answers count: " << count << " The most beloved film: " << film_max << endl;
  }
}
