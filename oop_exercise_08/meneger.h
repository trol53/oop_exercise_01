#ifndef MENEGER_H
#define MENEGER_H

#include "event.h"
#include <mutex>

class Meneger { //meneger message
    std::queue<Event> events;
    std::string file_names; //file for save
    char name_buff;
    public:
    Meneger(){ 
        file_names = "buffer";
        name_buff = 'a';
    } 
    void AddEvent(Event ev){
        events.push(ev);
    }
    void DoEvent(std::vector <Figure*> v){
        while(!events.empty()){ //do event save or print
            Event ev = events.front();
            events.pop();
            if (ev.IsFile()){
                std::string file_name = file_names; 
                file_name.push_back(name_buff);
                for (auto fig : v){
                    ev.Do(fig, file_name); //save
                }
                name_buff = name_buff + 1;
            } else {
                for (auto fig : v){
                    ev.Do(fig,file_names); //print
                }
            }
        }
    }
};

#endif