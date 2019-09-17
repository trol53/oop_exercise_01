// Лабораторная работа №1 Савров Никита М80-207Б-18
// Создать класс Address для работы с адресами домов. Адрес должен состоять из строк с названием города и
// улицы и чисел с номером дома и квартиры. Реализовать операции сравнения адресов, а также операции
// проверки принадлежности адреса к улице и городу. В операциях не должен учитываться регистр строки. Так
// же необходимо сделать операцию, которая возвращает истину если два адреса находятся по соседству (на
// одной улице в одном городе и дома стоят подряд).
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Address{
private:
   string city;
   string street;
   int house;
   int apartment;
 public:
   Address(){
     city = "Moscow";
     street = "Lenina";
     house = 10;
     apartment = 10;
   }
   void Set(string s1, string s2, int a1, int a2){
     city = s1;
     street = s2;
     house = a1;
     apartment = a2;
   }
   bool operator ==(Address a){
       transform(a.city.begin(), a.city.end(), a.city.begin(), (int (*)(int))tolower);
       transform(this->city.begin(), this->city.end(), this->city.begin(), (int (*)(int))tolower);
       transform(a.street.begin(), a.street.end(), a.street.begin(), (int (*)(int))tolower);
       transform(this->street.begin(), this->street.end(), this->street.begin(), (int (*)(int))tolower);
       return a.city == this->city && a.street == this->street && a.house == this->house && a.apartment == this->apartment;
   }
   bool is_city(string town){
     transform(town.begin(), town.end(), town.begin(), (int (*)(int))tolower);
     transform(this->city.begin(), this->city.end(), this->city.begin(), (int (*)(int))tolower);
     return this->city == town;
   }
   bool is_street(string stree){
     transform(stree.begin(), stree.end(), stree.begin(), (int (*)(int))tolower);
     transform(this->street.begin(), this->street.end(), this->street.begin(), (int (*)(int))tolower);
     return this->street == stree;
   }
   bool is_neighbour(Address a){
     transform(a.city.begin(), a.city.end(), a.city.begin(), (int (*)(int))tolower);
     transform(this->city.begin(), this->city.end(), this->city.begin(), (int (*)(int))tolower);
     transform(a.street.begin(), a.street.end(), a.street.begin(), (int (*)(int))tolower);
     transform(this->street.begin(), this->street.end(), this->street.begin(), (int (*)(int))tolower);
     if (a.city == this->city && a.street == this->street){
       if (abs(a.house - this->house) == 1){
         return true;
       }
     }
     return false;
   }
};

int main(){
  Address *a = new Address();
  Address *b = new Address();
  int item = 1;
  string name1,name2,town,stree;
  int adress;
  int name3,name4;
  cout << "1 - input address 1\n2 - input address 2\n3 - compare addresses\n4 - this address locate in this city\n5 - this address locate on this street\n6 - are this addresses neighbour\n0 - exit\n";
  while (item != 0){
    cin >> item;
    switch (item) {
      case 1:
      cout << "Enter Address 1\n";
      cin >> name1 >> name2 >> name3 >> name4;
      a->Set(name1, name2, name3, name4);
      break;
      case 2:
      cout << "Enter Address 2\n";
      cin >> name1 >> name2 >> name3 >> name4;
      b->Set(name1, name2, name3, name4);
      break;
      case 3:
      if (*a == *b)
        cout << "equal\n";
      else
        cout << "not equal\n";
      break;
      case 4:
      cout << "enter city and number address\n";
      cin >> town >> adress;
      if (adress == 1){
        if (a->is_city(town))
          cout << "this address locate in " << town << '\n';
        else
          cout << "this address not locate in " << town << '\n';
        break;
      }
      if (adress == 2){
        if (b->is_city(town))
          cout << "this address locate in " << town << '\n';
        else
          cout << "this address not locate in " << town << '\n';
        break;
      }
      cout << "this number not exist\n";
      break;
      case 5:
      cout << "enter sreet and number address\n";
      cin >> stree >> adress;
      if (adress == 1){
        if (a->is_street(stree))
          cout << "this address locate in " << stree << '\n';
        else
          cout << "this address not locate in " << stree << '\n';
        break;
      }
      if (adress == 2){
        if (a->is_street(stree))
          cout << "this address locate in " << stree << '\n';
        else
          cout << "this address not locate in " << stree << '\n';
        break;
      }
      cout << "this number not exist\n";
      break;
      case 6:
      if (a->is_neighbour(*b)){
        cout << "this addresses are neighbour\n";
      }else
        cout << "this addresses are not neighbour\n";
      break;
    }
    cout << "1 - input address 1\n2 - input address 2\n3 - compare addresses\n4 - this address locate in this city\n5 - this address locate on this street\n6 - are this addresses neighbour\n0 - exit\n";
  }
  delete(a);
  delete(b);
}
