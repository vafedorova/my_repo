#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
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
  string file_name = "results.txt";
  ofstream fout(file_name, ios::app);
  fout << name << " " << surname << " " << film << endl;
  fout.close();
  cout << "Вывести на экран содержимое файла? (Yes/No): ";
  string answer;
  cin >> answer;
  if (answer == "No" || answer == "no" || answer == "N" || answer == "n") {
    return 0;
  }
  else {
    ifstream fin(file_name);
    cout << fin.rdbuf() << endl;
    fin.close();
  }
}