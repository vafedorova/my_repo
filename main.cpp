#include <iostream>
#include <string>
#include <fstream>
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
    ifstream fin(file_name);
    cout << fin.rdbuf() << endl;
    fin.close();
  }
}
