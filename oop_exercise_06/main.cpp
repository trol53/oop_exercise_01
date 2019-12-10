#include "queue.h"
#include "rectangle.h"
#include "allocator.h"
#include <string>
#include <vector>
#include <cmath>


void Insert(Queue<Rectangle<int>> &q){ //function for insert element in queue
    Rectangle<int> tmp;
    std::cout << "enter 2 coordinats for 2 point\n"; 
    std::cin >> tmp;
    q.Push(tmp);
}

void Erase(Queue<Rectangle<int>> &q){ //function for delete element from queue
    q.Pop();
    std::cout << "First element is delete\n";
}

void PrintRectangle (Rectangle<int> tmp){
    std::cout << tmp << '\n';
}

void Print(Queue<Rectangle<int>> &q){ //function for print all figure
    std::for_each(q.Begin(), q.End(), [](Rectangle<int> a){
        PrintRectangle(a);
    });
}

void Count(Queue<Rectangle<int>> &q){ //function for count figures with square less test square
    int test;
    std::cout << "enter test square\n";
    std::cin >> test;
    int res =  std::count_if(q.Begin(), q.End(), [test](Rectangle<int> &a) -> bool{
        return a.Square() < test;
    });
    std::cout << res << " figures with square less " << test <<  '\n';
}

int main(){
    Queue<Rectangle<int>> q;
    std::string s;
    std::cout << "1 - Push to queue\n2 - Pop to queue\n3 - Print queue\n4 - Count square lower test\nq - exit\n";
    while (std::cin >> s){
        if (s == "1"){
            Insert(q);
        } else if (s == "2"){
            Erase(q);
        } else if (s == "3") {
            Print(q);
        } else if (s == "4"){
            Count(q);
        } else if (s == "q"){
            break;
        }
        std::cout << "1 - Push to queue\n2 - Pop to queue\n3 - Print queue\n4 - Count square lower test\nq - exit\n";
    }
}