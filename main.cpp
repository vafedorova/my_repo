/* Создайте в папке репозитория файл main.cpp с исходным кодом программы, запрашивающей при запуске имя и фамилию пользователя, а также название любимого фильма, и добавляющей эту информацию в конец текстового файла с результатами. */
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
  cin >> film;
  string file_name = "results.txt";
  ofstream fout(file_name, ios::app);
  fout << name << " " << surname << " " << film << endl;
}
