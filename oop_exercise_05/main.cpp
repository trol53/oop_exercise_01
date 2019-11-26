// Лабораторная работа №5 Савров Никита М80-207Б-18
// Разработать шаблоны классов согласно варианту задания. 
// Параметром шаблона должен являться скалярный тип данных задающий тип данных для оси координат. 
// Классы должны иметь публичные поля. Фигуры являются фигурами вращения. Для хранения координат 
// фигур необходимо использовать шаблон  std::pair.
// Создать шаблон динамической коллекцию, согласно варианту задания:
// 1.   	Коллекция должна быть реализована с помощью умных указателей (std::shared_ptr, std::weak_ptr). Опционально использование std::unique_ptr;
// 2.   	В качестве параметра шаблона коллекция должна принимать тип данных;
// 3.   	Реализовать forward_iterator по коллекции;
// 4.   	Коллекция должны возвращать итераторы begin() и  end();
// 5.   	Коллекция должна содержать метод вставки на позицию итератора insert(iterator);
// 6.   	Коллекция должна содержать метод удаления из позиции итератора erase(iterator);
// 7.   	При выполнении недопустимых операций (например выход аз границы коллекции или удаление не существующего элемента) необходимо генерировать исключения;
// 8.   	Итератор должен быть совместим со стандартными алгоритмами (например, std::count_if)
// 9.   	Коллекция должна содержать метод доступа: o Стек – pop, push, top; o Очередь – pop, push, top;
// oСписок, Динамический массив – доступ к элементу по оператору [];
// 10.	Реализовать программу, которая: o Позволяет вводить с клавиатуры фигуры (с типом int в качестве параметра шаблона фигуры) и добавлять в коллекцию;
// oПозволяет удалять элемент из коллекции по номеру элемента; o Выводит на экран введенные фигуры c помощью std::for_each; o Выводит на экран количество объектов, у которых площадь меньше заданной (с помощью 
// std::count_if);
// Вариант 20: Прямоугольник, Очередь.


#include "queue.h"
#include "rectangle.h"
#include <string>
#include <vector>
#include <cmath>

void Insert(Queue<Rectangle<int>> &q){
    Rectangle<int> tmp;
    std::cout << "enter coordinats for to points\n"; 
    std::cin >> tmp;
    q.Push(tmp);
}

void Erase(Queue<Rectangle<int>> &q){
    q.Pop();
}

void PrintRectangle (Rectangle<int> tmp){
    std::cout << tmp << '\n';
}

void Print(Queue<Rectangle<int>> &q){
    std::for_each(q.Begin(), q.End(), [](Rectangle<int> a){
        PrintRectangle(a);
    });
}

void Count(Queue<Rectangle<int>> &q){
    int test;
    std::cout << "enter test square\n";
    std::cin >> test;
    int res =  std::count_if(q.Begin(), q.End(), [test](Rectangle<int> &a) -> bool{
        return a.Square() < test;
    });
    std::cout << "Count = " << res << '\n';
}

int main(){
    Queue<Rectangle<int>> q;
    std::string s;
    std::cout << "1 - Push to queue\n2 - Pop to queue\n3 - Print queue\n4 - Count square lower test\n";
    while (std::cin >> s){
        if (s == "1"){
            Insert(q);
        } else if (s == "2"){
            Erase(q);
        } else if (s == "3") {
            Print(q);
        } else if (s == "4"){
            Count(q);
        }
        std::cout << "1 - Push to queue\n2 - Pop to queue\n3 - Print queue\n4 - Count square lower test\n";
    }
}