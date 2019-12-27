#ifndef RHOMB_H
#define RHOMB_H

#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include "figure.h"

class Rhomb : public Figure{ 
public:
    std::pair <double, double> a,b,c,d;
    int number_vertex = 4;
    std::string name;
    Rhomb(){
        a.first = 0;
        a.second = 0;
        b.first = 0;
        b.second = 0;
        c.first = 0;
        c.second = 0;
        d.first = 0;
        d.second = 0;
    }
    void Set (std::vector <std::pair<double,double>> cord){
        a.first = cord[0].first;
        a.second = cord[0].second;
        b.first = cord[1].first;
        b.second = cord[1].second;
        c.first = cord[2].first;
        c.second = cord[2].second;
        d.first = cord[3].first;
        d.second = cord[3].second;
        name = "rhomb";
    }
    std::string GetName(){
        return name;
    }
    std::vector <std::pair <double, double>> GetCoord(){
        std::vector <std::pair <double, double>> v(4);
        v[0].first = a.first;
        v[0].second = a.second;
        v[1].first = b.first;
        v[1].second = b.second;
        v[2].first = c.first;
        v[2].second = c.second;
        v[3].first = d.first;
        v[3].second = d.second;
        return v;
    }
    void Print(){
        std:: cout << a.first << " " << a.second << '\n';
        std:: cout << b.first << " " << b.second << '\n';
        std:: cout << c.first << " " << c.second << '\n';
        std:: cout << d.first << " " << d.second << '\n';
    }
    friend std::istream& operator>>(std::istream& in, Rhomb &obj){
        std::vector <std::pair <double,double>> v(4);
        int angle;
        double side, pi = M_PI;
        std::cin >> angle >> side;
        v[0].first = 0;
        v[0].second = 0;
        if (angle <= 90){
            double alpha = (90 - angle) / 2;
            v[3].second = sin(alpha * pi / 180) * side;
            v[3].first = cos(alpha * pi / 180) * side;
            v[1].first = sin(alpha * pi / 180) * side;
            v[1].second = cos(alpha * pi / 180) * side;
            v[2].second = sin(alpha * pi / 180) * side + v[1].second;
            v[2].first = cos(alpha * pi / 180) * side + v[1].first;
        } else if (angle < 180) {
            double alpha = (270 - angle) / 2;
            v[3].second = cos(alpha * pi / 180) * side;
            v[3].first = sin(alpha * pi / 180) * side;
            v[1].first = cos(alpha * pi / 180) * side;
            v[1].second = sin(alpha * pi / 180) * side;
            double d = sqrt(2 * side * side - 2 * side * side * (cos((180 - alpha) * pi / 180)));
            v[2].first = cos(45 * pi / 180) * side;
            v[2].second  = cos(45 * pi / 180) * side;
        } else {
            for (int i = 0; i < 4; i++){
                v[i].first = 0;
                v[i].second = 0;
            }
        }
        obj.Set(v);
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, Rhomb &obj){
            out << obj.a.first <<  " " << obj.a.second << '\n';
            out << obj.b.first <<  " " << obj.b.second << '\n';
            out << obj.c.first <<  " " << obj.c.second << '\n';
            out << obj.d.first <<  " " << obj.d.second << '\n';
            return out;
    }
};

#endif

