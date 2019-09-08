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
   Address(string name1, string name2, int name3, int name4){
     city = name1;
     street = name2;
     house = name3;
     apartment = name4;
   }
   void Set(){
     cin >> city >> street >> house >> apartment;
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
   bool is_neighbour(Address b){
     transform(a.city.begin(), a.city.end(), a.city.begin(), (int (*)(int))tolower);
     transform(this->city.begin(), this->city.end(), this->city.begin(), (int (*)(int))tolower);
     transform(a.street.begin(), a.street.end(), a.street.begin(), (int (*)(int))tolower);
     transform(this->street.begin(), this->street.end(), this->street.begin(), (int (*)(int))tolower);
     if (b.city == this->city && b.street == this->street){
       if (abs(b.house - this->house) == 1){
         return true;
       }
     }
     return false;
   }
};

int main(){
  // Address *a = new Address();
  // Address *b = new Address("MoscoW", "Lenina", 10, 15);
  // a->Set();
  // b->Set();
  // cout << (*a == *b);
  // string town,stree;
  // cout << "Enter street\n";
  // cin >> stree;
  // cout << a->is_street(stree);
  // cout << "Enter city\n";
  // cin >> town;
  // cout << a->is_city(town);
  
}
