// Реализации класса прямоугольник для ЛР №5.
// Савров Никита. Группа М80-207б-18
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>

template<class T>
class Rectangle{
public:
    std::pair <T, T> a,b,c,d;
    using type = T;
    int number_vertex = 4;
    int s;
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
    void Set (std::vector <std::pair<T,T>> cord){
        a.first = cord[0].first;
        a.second = cord[0].second;
        b.first = cord[1].first;
        b.second = cord[1].second;
        c.first = cord[2].first;
        c.second = cord[2].second;
        d.first = cord[3].first;
        d.second = cord[3].second;
        int a = abs(cord[1].second - cord[0].second);
        int b = abs(cord[3].first - cord[0].first);
        s = a*b;
    }
    int Square(){
        return s;
    }
    friend std::istream& operator>>(std::istream& in, Rectangle<T> &obj){
        std::vector <std::pair <T,T>> v(4);
        in >> v[0].first >> v[0].second >> v[2].first >> v[2].second;
        v[1].first = v[0].first;
        v[1].second = v[2].second;
        v[3].first = v[2].first;
        v[3].second = v[0].second;
        obj.Set(v);
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, Rectangle<T> &obj){
            out << obj.a.first <<  " " << obj.a.second << '\n';
            out << obj.b.first <<  " " << obj.b.second << '\n';
            out << obj.c.first <<  " " << obj.c.second << '\n';
            out << obj.d.first <<  " " << obj.d.second << '\n';
            return out;
    }
};

#endif