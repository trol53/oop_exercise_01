#include <iostream>
#include <string>
#include <algorithm>

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
   bool operator ==(Address a){
       transform(a.city.begin(), a.city.end(), a.city.begin(), tolower);
       transform(this->city.begin(), this->city.end(), this->city.begin(), tolower);
       return a.city == this->city && a.street == this->street && a.house == this->house && a.apartment == this->apartment;
   }
   //bool
};

int main(){
  Address *a = new Address();
  Address *b = new Address("MoscoW", "Lenina", 10, 10);
  cout << (*a == *b);
}
