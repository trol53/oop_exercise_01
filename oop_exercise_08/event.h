#ifndef EVENT_H
#define EVENT_H

#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
#include "figure.h"
#include <fstream>
#include "trapeze.h"
#include "rectangle.h"
#include "rhomb.h"
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <queue>

class Event {
    std::string type_event; //print or log
    bool is_file;
    std::string file_name; //file for save
    public:
    Event(std::string type){
        type_event = type;
        if (type_event == "print"){
            is_file = false;
            file_name = "NaN";
        } else {
            is_file = true;
        }
    }
    void Do(Figure *fig, std::string file){
        if (is_file){ //print or save
            file_name = file;
            std::ofstream oss;
            oss.open(file_name, std::ios::app);
            if (!oss.is_open()){
                std::cout << "cant open file\n";
                return;
            }
            std::vector <std::pair< double, double>> v(4); //coordinats vector
            v = fig->GetCoord();
            oss << fig->GetName() << '\n';
            for (int i = 0; i < 4; i++){
                oss << v[i].first << " " << v[i].second << '\n';
            }
        } else {
            std::cout << fig->GetName() << '\n';
            fig->Print();
        }
    }
    bool IsFile(){
        return is_file;
    }
};

#endif