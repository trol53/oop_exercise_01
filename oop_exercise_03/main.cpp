// Лабораторная работа №3 Савров Никита М80-207Б-18
// Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор общих методов:
// 1.   	Вычисление геометрического центра фигуры;
// 2.   	Вывод в стандартный поток вывода std::cout координат вершин фигуры; 3. Вычисление площади фигуры;
//  	Создать программу, которая позволяет:
// •       Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
// •       Сохранять созданные фигуры в динамический массив std::vector<Figure*>
// •   	Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
// •       Необходимо уметь вычислять общую площадь фигур в массиве.
// •       Удалять из массива фигуру по индексу;
// 	Фигуры, согласно варианту задания: Прямоугольник, трапеция, ромб.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Figure{
    public:
    virtual double Square () = 0;
    virtual void Print_figure () = 0;
    virtual pair<double, double> Geom_center () = 0; 
    virtual void Set (vector <pair <double, double>> cord) = 0;
    virtual bool IsFigure () = 0;
};

class Rectangle : public Figure  {
    private:
    int count_point = 4;
    vector <pair <double, double>> cordinats;
    public:
    Rectangle(){
        cordinats.resize(count_point);
        for (int i = 0; i < count_point; i++){
            cordinats[i].first = 0;
            cordinats[i].second = 0;
        }
    }
    void Set (vector <pair <double, double>> cord){
        for (int i = 0; i < count_point; i++){
            this->cordinats[i].first = cord[i].first;
            this->cordinats[i].second = cord[i].second;
        }
    }
    double Square (){
        double x_a = abs(cordinats[0].first - cordinats[1].first);
        double y_a = abs(cordinats[0].second - cordinats[1].second);
        double size_a = sqrt(x_a * x_a + y_a * y_a);
        double x_b = abs(cordinats[0].first - cordinats[3].first);
        double y_b = abs(cordinats[0].second - cordinats[3].second);
        double size_b = sqrt(x_b * x_b +  y_b * y_b);
        return size_a * size_b;
    }
    void Print_figure (){
        for (int i = 0; i < count_point; i++){
            cout << cordinats[i].first << " " << cordinats[i].second << '\n';
        }
        return;
    }
    pair<double, double> Geom_center (){
        return make_pair((cordinats[2].first - cordinats[0].first) / 2, (cordinats[2].second - cordinats[0].second) / 2);
    } 
    bool IsFigure (){
        if (cordinats[0].first != cordinats[1].first || cordinats[2].first != cordinats[3].first)
            return false;
        if (cordinats[0].second != cordinats[3].second || cordinats[1].second != cordinats[2].second)
            return false;
        return true;
    }
    friend istream& operator>>(istream& in, Rectangle &a){
        vector <pair <double, double>> v(4);
        for (int i = 0; i < 4; i++){
            in >> v[i].first >> v[i].second;
        }
        a.Set(v);
        return in;
    }
};

class Rhomb : public Figure {
    int count_point = 4;
    vector <pair <double, double>> cordinats;
    public:
    Rhomb(){
        cordinats.resize(count_point);
        for (int i = 0; i < count_point; i++){
            cordinats[i].first = 0;
            cordinats[i].second = 0;
        }
    }
    void Set (vector <pair <double, double>> cord){
        for (int i = 0; i < count_point; i++){
            this->cordinats[i].first = cord[i].first;
            this->cordinats[i].second = cord[i].second;
        }
    }
    public:
    double Square (){
        double x_d1 = abs(cordinats[0].first - cordinats[2].first);
        double y_d1 = abs(cordinats[0].second - cordinats[2].second);
        double size_d1 = sqrt(x_d1 * x_d1 + y_d1 * y_d1);
        double x_d2 = abs(cordinats[1].first - cordinats[3].first);
        double y_d2 = abs(cordinats[1].second - cordinats[3].second);
        double size_d2 = sqrt(x_d2 * x_d2 + y_d2 * y_d2);
        return size_d1 * size_d2 / 2;
    }
    void Print_figure (){
        for (int i = 0; i < count_point; i++){
            cout << cordinats[i].first << " " << cordinats[i].second << '\n';
        }
        return;
    }
    pair<double, double> Geom_center (){
        return make_pair((cordinats[2].first - cordinats[0].first) / 2, (cordinats[2].second - cordinats[0].second) / 2);
    }
    bool IsFigure (){
        double x_a = abs(cordinats[0].first - cordinats[1].first);
        double y_a = abs(cordinats[0].second - cordinats[1].second);
        double size_a = sqrt(x_a * x_a + y_a * y_a);
        double x_b = abs(cordinats[0].first - cordinats[3].first);
        double y_b = abs(cordinats[0].second - cordinats[3].second);
        double size_b = sqrt(x_b * x_b +  y_b * y_b);
        double x_c = abs(cordinats[1].first - cordinats[2].first);
        double y_c = abs(cordinats[1].second - cordinats[2].second);
        double size_c = sqrt(x_c * x_c + y_c * y_c);
        double x_d = abs(cordinats[2].first - cordinats[3].first);
        double y_d = abs(cordinats[2].second - cordinats[3].second);
        double size_d = sqrt(x_d * x_d +  y_d * y_d);
        if (size_a != size_b || size_a != size_c || size_a != size_d)
            return false;
        return true;
    }
    friend istream& operator>>(istream& in, Rhomb &a){
        vector <pair <double, double>> v(4);
        for (int i = 0; i < 4; i++){
            in >> v[i].first >> v[i].second;
        }
        a.Set(v);
        return in;
    }
};

class Trapeze : public Figure {
    int count_point = 4;
    vector <pair <double, double>> cordinats;
    public:
    Trapeze(){
        cordinats.resize(count_point);
        for (int i = 0; i < count_point; i++){
            cordinats[i].first = 0;
            cordinats[i].second = 0;
        }
    }
    void Set(vector <pair <double, double>> cord){
        for (int i = 0; i < count_point; i++){
            this->cordinats[i].first = cord[i].first;
            this->cordinats[i].second = cord[i].second;
        }
    }
    double Square(){
        double h = cordinats[1].second - cordinats[0].second;
        double a = cordinats[2].first - cordinats[1].first;
        double b = cordinats[3].first - cordinats[0].first;
        return ((a + b) / 2) * h;
    }
    void Print_figure (){
        for (int i = 0; i < count_point; i++){
            cout << cordinats[i].first << " " << cordinats[i].second << '\n';
        }
    }
    pair <double, double> Geom_center (){
        double h = cordinats[1].second - cordinats[0].second;
        double a = cordinats[2].first - cordinats[1].first;
        double b = cordinats[3].first - cordinats[0].first;
        double mid_a_x = (cordinats[2].first + cordinats[1].first) / 2;
        double mid_a_y = cordinats[1].second;
        double mid_b_x = (cordinats[3].first + cordinats[0].first) / 2;
        double mid_b_y = cordinats[0].second;
        double k = (mid_b_y - mid_a_y) / (mid_b_x - mid_a_x);
        double c = mid_a_y - k * mid_a_x;
        double y = (h / 3) * (2 * b + a) / (a + b);
        double x = (y - c) / k;
        return make_pair(x,y);
    }
    bool IsFigure (){
        if (cordinats[0].second == cordinats[3].second && cordinats[1].second == cordinats[2].second)
            return true;
        if (cordinats[0].first == cordinats[1].first && cordinats[3].first == cordinats[2].first)
            return true;
        return false;
    }
    friend istream& operator>>(istream& in, Trapeze &a){
        vector <pair <double, double>> v(4);
        for (int i = 0; i < 4; i++){
            in >> v[i].first >> v[i].second;
        }
        a.Set(v);
        return in;
    }
};

int main(){
    vector <Figure*> f(10);
    int f_size = 0;
    pair <double, double> p;
    vector <pair <double, double>> v1(4);
    double sum;
    char menu = '0';
    Rectangle tmp_r;
    Rhomb tmp_rh;
    Trapeze tmp_t;
    while (menu != '9'){
        cout << "1 - enter rectangle\n2 - enter rhomb\n3 - enter trapeze\n4 - square for all figure\n5 - geomcenter for all figure\n6 - print all figure\n7 - all square\n8 - erase figure\n9 - exit\n";
        cin >> menu;
        switch (menu)
        {
        case '1':
            if (f.size() <= f_size)
                f.resize(2 * f_size);
            cout << "input cordinats\n";
            cin >> tmp_r;
            f[f_size] = new Rectangle(tmp_r);
            if (f[f_size]->IsFigure()){
                f_size++;
            }else{
                cout << "wrong input\n";
                delete(f[f_size]);
                f.pop_back();
            }
            break;
        case '2':
            cout << "input cordinats\n";
            if (f.size() <= f_size){
                f.resize(2 * f_size);
            }
            cin >> tmp_rh;
            f[f_size] = new Rhomb(tmp_rh);
            if (f[f_size]->IsFigure()){
                f_size++;
            }else{
                cout << "wrong input\n";
                delete(f[f_size]);
                f.pop_back();
            }
            break;
        case '3':
            cout << "input cordinats\n";
            if (f.size() <= f_size){
                f.resize(2 * f_size);
            }
            cin >> tmp_t;
            f[f_size] = new Trapeze(tmp_t);
            if (f[f_size]->IsFigure()){
                f_size++;
            }else{
                cout << "wrong input\n";
                delete(f[f_size]);
                f.pop_back();
            }
            break;
        case '4':
            for (int i = 0; i < f_size; i++){
                cout << "square figure number - " << i << '\n' << f[i]->Square() << '\n';
            }
            break;
        case '5':
            for (int i = 0; i < f_size; i++){
                p = f[i]->Geom_center();
                cout << "geom-center figure number - " << i << '\n' << p.first << " " << p.second << '\n';
            }
            break;
        case '6':
            for (int i = 0; i < f_size; i++){
                cout << "cordinats figure number - " << i << '\n';
                f[i]->Print_figure();
            }
            break;
        case '7':
            sum = 0;
            for (int i = 0; i < f_size; i++){
                sum += f[i]->Square();
            }
            cout << "all square = " << sum << '\n';
            break;
        case '8':
            cout << "input index\n";
            int j;
            cin >> j;
            if (j >= f_size){
                cout << "not exist\n";
                break;
            }
            for (int i = j; i < f_size - 1; i++){
                swap(f[i], f[i + 1]);
            }
            delete(f[f_size]);
            f.pop_back();
            f_size--;
            break;
        default:
            break;
        }
    }
}
