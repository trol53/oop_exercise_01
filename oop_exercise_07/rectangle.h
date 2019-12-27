#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include "figure.h"

class Rectangle : public Figure{
public:
    std::pair <double, double> a,b,c,d;
    int number_vertex = 4;
    std::string name;
    Rectangle(){
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
        name = "rectangle";
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
    friend std::istream& operator>>(std::istream& in, Rectangle &obj){
        std::vector <std::pair <double,double>> v(4);
        in >> v[0].first >> v[0].second >> v[2].first >> v[2].second;
        v[1].first = v[0].first;
        v[1].second = v[2].second;
        v[3].first = v[2].first;
        v[3].second = v[0].second;
        obj.Set(v);
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, Rectangle &obj){
            out << obj.a.first <<  " " << obj.a.second << '\n';
            out << obj.b.first <<  " " << obj.b.second << '\n';
            out << obj.c.first <<  " " << obj.c.second << '\n';
            out << obj.d.first <<  " " << obj.d.second << '\n';
            return out;
    }
};

#endif