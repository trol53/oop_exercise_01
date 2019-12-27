// Лабораторная работа №7 Савров Никита М80-207Б-18
// Спроектировать простейший графический векторный редактор.
// Требование к функционалу редактора:
// • создание нового документа
// • импорт документа из файла
// • экспорт документа в файл
// • создание графического примитива (согласно варианту задания)
// • удаление графического примитива
// • отображение документа на экране (печать перечня графических объектов и их характеристик)
// • реализовать операцию undo, отменяющую последнее сделанное действие. Должно действовать для
// операций добавления/удаления фигур.
// Требования к реализации:
// • Создание графических примитивов необходимо вынести в отдельный класс – Factory.
// • Сделать упор на использовании полиморфизма при работе с фигурами;
// • Взаимодействие с пользователем (ввод команд) реализовать в функции main;

#include "factory.h"

int main(){
    std::string input;
    Factory docs;
    bool check;
    std::cout << "1 - create new document\n2 - add trapeze\n3 - add rectangle\n4 - add rhomb\n5 - remove last figure\n6 - print document\n7 - undo\n8 - save\n9 - load\n0 - show\n";
    while (std::cin >> input){
        if (input == "1"){
            std::string name_d, name_f;
            std::cout << "input name doc and file\n";
            std::cin >> name_d >> name_f;
            docs.CreateDocument(name_f,name_d);
        } else if (input == "2"){
            check = docs.AddTrapeze();
        } else if (input == "3"){
            check = docs.AddRectangle();
        } else if (input == "4"){
            check = docs.AddRhomb();
        } else if (input == "5"){
            check = docs.RemoveFigure();
        } else if (input == "6"){
            docs.PrintDocument();
        } else if(input == "7"){
            check = docs.UnDo();
        } else if(input == "8"){
            check = docs.Save();
        } else if(input == "9"){
            std::string name;
            std::cout << "input name file\n";
            std::cin >> name;
            check = docs.Load(name);
        } else if(input == "0"){
            docs.Show();
        } else {
            std::cout << "check menu\n";
        }
        std::cout << "1 - create new document\n2 - add trapeze\n3 - add rectangle\n4 - add rhomb\n5 - remove last figure\n6 - print document\n7 - undo\n8 - save\n9 - load\n0 - show\n";
    }
}