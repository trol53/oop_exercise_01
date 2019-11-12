// Лабораторная работа №4 Савров Никита М80-207Б-18
// Разработать шаблоны классов согласно варианту задания.  Параметром шаблона должен являться скалярный тип данных задающий тип 
// данных для оси координат. Классы должны иметь публичные поля. Фигуры являются фигурами вращения. 
// Для хранения координат фигур необходимо использовать шаблон  std::pair.
// Создать набор шаблонов, создающих функции, реализующие:
// 1.   	Вычисление геометрического центра фигуры;
// 2.   	Вывод в стандартный поток вывода std::cout координат вершин фигуры;
// 3.   	Вычисление площади фигуры;
// Параметром шаблона должен являться тип класса фигуры ( например Square<int>). Помимо самого класса фигуры, шаблонная функция должна уметь работать с tuple. Например, std::tuple<std::pair<int,int>, std::pair<int,int>, std::pair<int,int>> должен интерпретироваться как треугольник. std::tuple<std::pair<int,int>, std::pair<int,int>, std::pair<int,int>, std::pair<int,int>> - как квадрат. Каждый std::pair<int,int> - соответствует координатам вершины фигуры вращения.
 
// Создать программу, которая позволяет:
// •  Вводить из стандартного ввода std::cin фигуры, согласно варианту задания (как в виде класса, так и в виде std::tuple).
// •  Вызывать для нее шаблонные функции (1-3).
// 	Фигуры, согласно варианту задания: Прямоугольник, трапеция, ромб.
#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

template<class T>
class Rectangle{
public:
    pair <T, T> a,b,c,d;
    using type = T;
    int number_vertex = 4;
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
    void Set (vector <pair<T,T>> cord){
        a.first = cord[0].first;
        a.second = cord[0].second;
        b.first = cord[1].first;
        b.second = cord[1].second;
        c.first = cord[2].first;
        c.second = cord[2].second;
        d.first = cord[3].first;
        d.second = cord[3].second;
    }
    void Set (tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>> t){
        a = get<0>(t);
        b = get<1>(t);
        c = get<2>(t);
        d = get<3>(t);
    }
    friend istream& operator>>(istream& in, Rectangle<T> &obj){
        vector <pair <T,T>> v(4);
        in >> v[0].first >> v[0].second >> v[2].first >> v[2].second;
        v[1].first = v[0].first;
        v[1].second = v[2].second;
        v[3].first = v[2].first;
        v[3].second = v[0].second;
        obj.Set(v);
        return in;
    }
    friend ostream& operator<<(ostream& out, Rectangle<T> &obj){
            out << obj.a.first <<  " " << obj.a.second << '\n';
            out << obj.b.first <<  " " << obj.b.second << '\n';
            out << obj.c.first <<  " " << obj.c.second << '\n';
            out << obj.d.first <<  " " << obj.d.second << '\n';
            return out;
    }
};

template<class T>
class Rhomb{
public:
    pair <T, T> a,b,c,d;
    using type = T;
    int number_vertex = 4;
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
    void Set (vector <pair<T,T>> cord){
        a.first = cord[0].first;
        a.second = cord[0].second;
        b.first = cord[1].first;
        b.second = cord[1].second;
        c.first = cord[2].first;
        c.second = cord[2].second;
        d.first = cord[3].first;
        d.second = cord[3].second;
    }
    void Set (tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>> t){
        a = get<0>(t);
        b = get<1>(t);
        c = get<2>(t);
        d = get<3>(t);
    }
    friend istream& operator>>(istream& in, Rhomb<T> &obj){
        vector <pair <double,double>> v(4);
        int angle;
        double side, pi = 3.14;
        cin >> angle >> side;
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
            cout << "lol'\n";
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
    friend ostream& operator<<(ostream& out, Rhomb<T> &obj){
            out << obj.a.first <<  " " << obj.a.second << '\n';
            out << obj.b.first <<  " " << obj.b.second << '\n';
            out << obj.c.first <<  " " << obj.c.second << '\n';
            out << obj.d.first <<  " " << obj.d.second << '\n';
            return out;
    }
};

template<class T>
class Trapeze{
public:
    pair <T, T> a,b,c,d;
    using type = T;
    int number_vertex = 4;
    Trapeze(){
        a.first = 0;
        a.second = 0;
        b.first = 0;
        b.second = 0;
        c.first = 0;
        c.second = 0;
        d.first = 0;
        d.second = 0;
    }
    void Set (vector <pair<T,T>> cord){
        a.first = cord[0].first;
        a.second = cord[0].second;
        b.first = cord[1].first;
        b.second = cord[1].second;
        c.first = cord[2].first;
        c.second = cord[2].second;
        d.first = cord[3].first;
        d.second = cord[3].second;
    }
    void Set (tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>> t){
        a = get<0>(t);
        b = get<1>(t);
        c = get<2>(t);
        d = get<3>(t);
    }
    friend istream& operator>>(istream& in, Trapeze<T> &obj){
        vector <pair <T,T>> v(4);
        for (int i = 0; i < 4; i++){
            in >> v[i].first >> v[i].second;
        }
        obj.Set(v);
        return in;
    }
    friend ostream& operator<<(ostream& out, Trapeze<T> &obj){
            out << obj.a.first <<  " " << obj.a.second << '\n';
            out << obj.b.first <<  " " << obj.b.second << '\n';
            out << obj.c.first <<  " " << obj.c.second << '\n';
            out << obj.d.first <<  " " << obj.d.second << '\n';
            return out;
    }
};

template <class T>
typename enable_if <is_same<T, tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>>>::value,istream&>::type operator>>(istream& in, T &obj){
    pair <int, int> a,b,c,d;
    in >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>> t(a,b,c,d);
    obj = t;
    return in;
}

template <class T>
typename enable_if <is_same<T, tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>>>::value,ostream&>::type operator<<(ostream& out, T &obj){
        out << get<0>(obj).first <<  " " << get<0>(obj).second << '\n';
        out << get<1>(obj).first <<  " " << get<1>(obj).second << '\n';
        out << get<2>(obj).first <<  " " << get<2>(obj).second << '\n';
        out << get<3>(obj).first <<  " " << get<3>(obj).second << '\n';
        return out;
}

template<class T>
typename enable_if <is_same<T, tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>>>::value,int>::type Square(T shape){
    int x0 = get<0>(shape).first;
    int x1 = get<1>(shape).first;
    int x2 = get<2>(shape).first;
    int x3 = get<3>(shape).first;
    int x4 = x0;
    int y0 = get<0>(shape).second;
    int y1 = get<1>(shape).second;
    int y2 = get<2>(shape).second;
    int y3 = get<3>(shape).second;
    int y4 = y0;
    double r1 = 0,r2 = 0;
    r1 = x0*y1 + x1*y2 + x2*y3 + x3*y4;
    r2 = y0*x1 + y1*x2 + y2*x3 + y3*x4;
    return (r1 - r2) / 2;
}

template<class T>
typename enable_if <!is_same<T, tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>>>::value,double>::type Square(T shape){
    typename T::type x0 = shape.a.first;
    typename T::type x1 = shape.b.first;
    typename T::type x2 = shape.c.first;
    typename T::type x3 = shape.d.first;
    typename T::type x4 = x0;
    typename T::type y0 = shape.a.second;
    typename T::type y1 = shape.b.second;
    typename T::type y2 = shape.c.second;
    typename T::type y3 = shape.d.second;
    typename T::type y4 = y0;
    double r1 = 0,r2 = 0;
    r1 = x0*y1 + x1*y2 + x2*y3 + x3*y4;
    r2 = y0*x1 + y1*x2 + y2*x3 + y3*x4;
    return (r1 - r2) / 2;
}

template<class T>
typename enable_if <is_same<T, tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>>>::value,pair <double, double>>::type Center(T shape){
    int x0 = get<0>(shape).first;
    int x1 = get<1>(shape).first;
    int x2 = get<2>(shape).first;
    int x3 = get<3>(shape).first;
    int x4 = x0;
    int y0 = get<0>(shape).second;
    int y1 = get<1>(shape).second;
    int y2 = get<2>(shape).second;
    int y3 = get<3>(shape).second;
    int y4 = y0;
    double r1 = 0,r2 = 0,s = 0;
    s = 0.5 * (x0*y1 - x1*y0 + x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y4 - x4*y3);
    r1 = (x0 + x1)*(x0*y1 - x1*y0) + (x1 + x2)*(x1*y2 - x2*y1) + (x2 + x3)*(x2*y3 - x3*y2) + (x3 + x4)*(x3*y4 - x4*y3);
    r2 = (y0 + y1)*(x0*y1 - x1*y0) + (y1 + y2)*(x1*y2 - x2*y1) + (y2 + y3)*(x2*y3 - x3*y2) + (y3 + y4)*(x3*y4 - x4*y3);
    return make_pair(r1 * (1 / (6 * s)), r2 * (1 / (6 * s)));
}

template<class T>
typename enable_if <!is_same<T, tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>>>::value,pair <double, double>>::type Center(T shape){
    typename T::type x0 = shape.a.first;
    typename T::type x1 = shape.b.first;
    typename T::type x2 = shape.c.first;
    typename T::type x3 = shape.d.first;
    typename T::type x4 = x0;
    typename T::type y0 = shape.a.second;
    typename T::type y1 = shape.b.second;
    typename T::type y2 = shape.c.second;
    typename T::type y3 = shape.d.second;
    typename T::type y4 = y0;
    double r1 = 0,r2 = 0, s = 0;
    s = 0.5 * (x0*y1 - x1*y0 + x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y4 - x4*y3);
    r1 = (x0 + x1)*(x0*y1 - x1*y0) + (x1 + x2)*(x1*y2 - x2*y1) + (x2 + x3)*(x2*y3 - x3*y2) + (x3 + x4)*(x3*y4 - x4*y3);
    r2 = (y0 + y1)*(x0*y1 - x1*y0) + (y1 + y2)*(x1*y2 - x2*y1) + (y2 + y3)*(x2*y3 - x3*y2) + (y3 + y4)*(x3*y4 - x4*y3);
    return make_pair(r1 * (1 / (6 * s)), r2 * (1 / (6 * s)));
}

int main(){

    tuple<pair <int, int>, pair <int, int>, pair <int, int>, pair <int, int>> t;
    Rectangle<double> tmp_rec;
    Rhomb<double> tmp_rh;
    Trapeze<double> tmp_t;
    pair <double, double> p;
    p.first = 0;
    p.second = 0;
    int check = 0, checkp = 0;
    char menu = '1';
    double s = 0;
    cout << "program for work with figures\n";
    while (menu != '0'){
        cout << "1 - enter rectangle\n2 - enter rhomb\n3 - enter trapeze\n4 - square for figure\n5 - geomcenter for figure\n6 - print figure\n7 - enter tuple\n8 - square tuple\n9 - center tuple\na - print tuple\n0 - exit\n";
        cin >> menu;
        switch (menu)
        {
        case '1':
            cout << "input cordinats(2 vertex)\n";
            cin >> tmp_rec;
            check = 1;
            break;
        case '2':
            cout << "input rhomb(angle and side)\n";
            cin >> tmp_rh;
            check = 2;
            break;
        case '3':
            cout << "input cordinats(4 vertex)\n";
            cin >> tmp_t;
            check = 3;
            break;
        case '4':
            if (check == 1){
                s = Square(tmp_rec);
            } else if (check == 2){
                s = Square(tmp_rh);
            } else if (check == 3){
                s = Square(tmp_t);
            }
            if (s == 0){
                cout << "wrong figure\n";
            } else {
                cout << "square for figure = " << abs(s) << '\n'; 
            }
            break;
        case '5':
            if (check == 1){
                p = Center(tmp_rec);
            } else if (check == 2){
                p = Center(tmp_rh);
            } else if (check == 3){
                p = Center(tmp_t);
            }
            if (p.first == 0 && p.second == 0){
                cout << "wrong figure\n";
            } else{
                cout << "center = " << p.first << " " << p.second << '\n';
            }
            break;
        case '6':
            if (check == 1){
                cout << tmp_rec;
            } else if (check == 2){
                cout << tmp_rh;
            } else if (check == 3){
                cout << tmp_t;
            } else {
                "wrong figure\n";
            }
            break;
        case '7':
            cout << "enter coordinats (4 vertex)\n";
            cin >> t;
            checkp = 1;
            break;
        case '8':
            s = Square(t);
            cout << abs(s);
            break;
        case '9':
            p = Center(t);
            cout << p.first << " " << p.second << '\n';
            break;
        case 'a':
            if (checkp == 1)
                cout << t;
            else 
                cout << "wrong tuple\n";
        default:
            break;
        }
    }
}