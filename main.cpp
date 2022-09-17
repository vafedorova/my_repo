#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
  cout << "Введите Ваше имя: ";
  string name;
  cin >> name;
  cout << "Введите Вашу фамилию: ";
  string surname;
  cin >> surname;
  cout << "Введите Вашу любимую книгу: ";
  string book;
  cin >> book;
  string file_name = "results.txt";
  ofstream fout(file_name, ios::app);
  fout << name << " " << surname << " " << book << endl;
}
