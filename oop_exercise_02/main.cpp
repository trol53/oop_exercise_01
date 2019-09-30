// Лабораторная работа №2 Савров Никита М80-207Б-18
// Создать класс Address для работы с адресами домов. Адрес должен состоять из строк с названием города и улицы и чисел с номером дома и квартиры.
// Реализовать операции сравнения адресов, а также операции проверки принадлежности адреса к улице и городу. В операциях не должен учитываться регистр строки.
// Так же необходимо сделать операцию, которая возвращает истину если два адреса находятся по соседству (на одной улице в одном городе и дома стоят подряд).
// Операцию сравнения равенства реализовать в виде перегрузки оператора. Операцию нахождения «по соседству» реализовать в виде перегрузки оператора &.
// Необходимо реализовать пользовательский литерал для работы с константами типа Address.
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Address{
public:
   string city;
   string street;
   unsigned long long int house;
   unsigned long long int apartment;
   Address(){
     city = "";
     street = "";
     house = 0;
     apartment = 0;
   }
   Address(string str1, string str2, unsigned long long int hous, unsigned long long int home){
     city = str1;
     street = str2;
     house = hous;
     apartment = home;
   }
   void Set(string s1, string s2, unsigned long long int a1, unsigned long long int a2){
     city = s1;
     street = s2;
     house = a1;
     apartment = a2;
   }
   bool is_city(string town){
     transform(town.begin(), town.end(), town.begin(), (int (*)(int))tolower);
     transform(city.begin(), city.end(), city.begin(), (int (*)(int))tolower);
     return city == town;
   }
   bool is_street(string stree){
     transform(stree.begin(), stree.end(), stree.begin(), (int (*)(int))tolower);
     transform(this->street.begin(), this->street.end(), this->street.begin(), (int (*)(int))tolower);
     return this->street == stree;
   }
};

bool operator ==(Address a, Address b){
    transform(a.city.begin(), a.city.end(), a.city.begin(), (int (*)(int))tolower);
    transform(b.city.begin(), b.city.end(), b.city.begin(), (int (*)(int))tolower);
    transform(a.street.begin(), a.street.end(), a.street.begin(), (int (*)(int))tolower);
    transform(b.street.begin(), b.street.end(), b.street.begin(), (int (*)(int))tolower);
    return a.city == b.city && a.street == b.street && a.house == b.house && a.apartment == b.apartment;
}
Address operator +(Address a, Address b){
  Address result;
  result.city = a.city + b.city;
  result.street = a.street + b.street;
  result.house = a.house + b.house;
  result.apartment = a.apartment + b.apartment;
  return result;
}

bool operator &(Address a, Address b){
  transform(a.city.begin(), a.city.end(), a.city.begin(), (int (*)(int))tolower);
  transform(b.city.begin(), b.city.end(), b.city.begin(), (int (*)(int))tolower);
  transform(a.street.begin(), a.street.end(), a.street.begin(), (int (*)(int))tolower);
  transform(b.street.begin(), b.street.end(), b.street.begin(), (int (*)(int))tolower);
  if (a.city == b.city && a.street == b.street){
    if (a.house > b.house)
    if (a.house - b.house == 1){
      return true;
    }
    if (a.house < b.house)
    if (b.house - a.house == 1){
      return true;
    }
  }
  return false;
}

Address operator ""_cit (const char *ans, size_t){
  string str(ans);
  return Address(str,"",0,0);
}

Address operator ""_stree (const char *ans, size_t){
  string str(ans);
  return Address("",str,0,0);
}

Address operator ""_hom (unsigned long long int x){
  return Address("","",x,0);
}

Address operator ""_aps (unsigned long long int y){
  return Address("","",0,y);
}

int main(){
  Address a("","",0,0);
  Address b("","",0,0);
  Address c = "Moscow"_cit + "Mira"_stree + 10_hom + 12_aps;
  Address d = "Stalingrad"_cit + "Lenina"_stree + 15_hom + 20_aps;
  cout << "Literal test\n" << c.city << " " << c.street << " " << c.house << " " << c.apartment << "\n";
  cout << d.city << " " << d.street << " " << d.house << " " << d.apartment << "\n";
  unsigned long long int item = 1;
  string name1,name2,town,stree;
  unsigned long long int adress;
  unsigned long long int name3,name4;
  cout << "1 - input address 1\n2 - input address 2\n3 - compare addresses\n4 - this address locate in this city\n5 - this address locate on this street\n6 - are this addresses neighbour\n0 - exit\n";
  while (item != 0){
    cin >> item;
    switch (item) {
      case 1:
      cout << "Enter Address 1\n";
      cin >> name1 >> name2 >> name3 >> name4;
      a.Set(name1, name2, name3, name4);
      break;
      case 2:
      cout << "Enter Address 2\n";
      cin >> name1 >> name2 >> name3 >> name4;
      b.Set(name1, name2, name3, name4);
      break;
      case 3:
      if (a == b)
        cout << "equal\n";
      else
        cout << "not equal\n";
      break;
      case 4:
      cout << "enter city and number address\n";
      cin >> town >> adress;
      if (adress == 1){
        if (a.is_city(town))
          cout << "this address locate in " << town << '\n';
        else
          cout << "this address not locate in " << town << '\n';
        break;
      }
      if (adress == 2){
        if (b.is_city(town))
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
        if (a.is_street(stree))
          cout << "this address locate in " << stree << '\n';
        else
          cout << "this address not locate in " << stree << '\n';
        break;
      }
      if (adress == 2){
        if (a.is_street(stree))
          cout << "this address locate in " << stree << '\n';
        else
          cout << "this address not locate in " << stree << '\n';
        break;
      }
      cout << "this number not exist\n";
      break;
      case 6:
      if (a & b){
        cout << "this addresses are neighbour\n";
      }else
        cout << "this addresses are not neighbour\n";
      break;
    }
    cout << "1 - input address 1\n2 - input address 2\n3 - compare addresses\n4 - this address locate in this city\n5 - this address locate on this street\n6 - are this addresses neighbour\n0 - exit\n";
  }
}
