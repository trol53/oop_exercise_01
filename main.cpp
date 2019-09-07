#include <iostream>
#include <string>

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
   bool operator ==(Address &a, Adress &b){
     return a.city == b.city && a.street == b.street && a.house == b.house && a.apartment == b.apartment;
   }
};
