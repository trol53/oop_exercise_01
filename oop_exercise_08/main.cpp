// Лабораторная работа №8 Савров Никита М80-207Б-18
// Создать приложение, которое будет считывать из стандартного ввода данные фигур, согласно варианту
// задания, выводить их характеристики на экран и записывать в файл. Фигуры могут задаваться как своими
// вершинами, так и другими характеристиками (например, координата центра, количество точек и радиус).
// Программа должна:
// 1. Осуществлять ввод из стандартного ввода данных фигур, согласно варианту задания;
// 2. Программа должна создавать классы, соответствующие введенным данных фигур;
// 3. Программа должна содержать внутренний буфер, в который помещаются фигуры. Для создания
// буфера допускается использовать стандартные контейнеры STL. Размер буфера задается параметром
// командной строки. Например, для буфера размером 10 фигур: oop_exercise_08 10
// 4. При накоплении буфера они должны запускаться на асинхронную обработку, после чего буфер
// должен очищаться;
// 5. Обработка должна производиться в отдельном потоке;
// 6. Реализовать два обработчика, которые должны обрабатывать данные буфера:
// a. Вывод информации о фигурах в буфере на экран;

// b. Вывод информации о фигурах в буфере в файл. Для каждого буфера должен создаваться файл
// с уникальным именем.

// 7. Оба обработчика должны обрабатывать каждый введенный буфер. Т.е. после каждого заполнения
// буфера его содержимое должно выводиться как на экран, так и в файл.
// 8. В программе должно быть ровно два потока (thread). Один основной (main) и второй для
// обработчиков;
// 9. В программе должен явно прослеживаться шаблон Publish-Subscribe. Каждый обработчик должен
// быть реализован как отдельный подписчик.
// 10. Реализовать в основном потоке (main) ожидание обработки буфера в потоке-обработчике. Т.е. после
// отправки буфера на обработку основной поток должен ждать, пока поток обработчик выведет данные
// на экран и запишет в файл.
#include "meneger.h"
#include <thread>
#include "input.h"


void Subscribe(std::vector <Figure*> &buffer, Meneger &man){ //method for do event/subscribe
    Event ev1("print");
    Event ev2("log");
    man.AddEvent(ev1);
    man.AddEvent(ev2);
    man.DoEvent(buffer);
}

int main(int argc, char *argv[]){
    int buff_size;
    if (argc < 2){
        buff_size = 3;
    } else
        buff_size = std::atoi(argv[1]); //argument cmd
    std::vector <Figure*> buffer;
    std::string input;
    Meneger man;
    std::cout << "1 - add rectangle\n2 - add rhomb\n3 - trapeze\n";
    while(std::cin >> input){
        if (input == "1"){
            AddRectangle(buffer);
        } else if (input == "2"){
            AddRhomb(buffer);
        } else if (input == "3"){
            AddTrapeze(buffer);
        } else {
            std::cout << "check menu\n";
        }
        if (buffer.size() == buff_size){ //if buffer full do event
            std::thread thread(Subscribe, std::ref(buffer), std::ref(man));
            thread.join();
            std::cout.flush();
            buffer.clear();
            buffer.resize(0);
        }
        std::cout << "1 - add rectangle\n2 - add rhomb\n3 - trapeze\n";
    }

}