#ifndef FACTORY_H
#define FACTORY_H

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


class Factory {
    private:
    std::string file_name;
    std::string doc_name;
    std::ofstream file;
    std::stack<std::pair <std::string, Figure*>> comand;
    bool check_empty;
    std::vector <Figure*> figures;
    public:
    Factory(){
        file_name = "";
        doc_name = "";
        check_empty = true;
    }
    bool CreateDocument(std::string name_f, std::string name_d){
        file_name = name_f;
        doc_name = name_d;
        if (file.is_open()){
            file.close();
        }
        file.open(file_name);
        if (!file.is_open()){
            std::cout << "cant open file\n";
            return false;
        }
        if (comand.size() != 0){
            while (!comand.empty()){
                comand.pop();
            }
        }
        figures.clear();
        check_empty = false;
        std::cout << "Succesfull\n";
        return true;
    }
    bool Save(){
        if (check_empty){
            std::cout << "document is empty\n";
            return false;
        }
        if (file.is_open()){
            file.close();
            file.open(file_name);
        }
        file << doc_name << " " << "count figures = " << figures.size() << '\n';
        for (auto fig : figures){
            file << fig->GetName() << '\n';
            std::vector <std::pair<double, double>> v = fig->GetCoord(); 
            for (int i = 0; i < 4; i++){
                file << v[i].first << " " << v[i].second << '\n';
            }
        }
        file.close();
        return true;
    }
    bool IsEmpty(){
        return check_empty;
    }
    bool IsCorrect(std::string check){
        for (int i = 0; i < check.size(); i++){
            if (check[i] < '0' || check[i] > '9'){
                return false;
            }
        }
        return true;
    }
    bool AddRectangle(){
        if (check_empty){
            std::cout << "document is empty\n";
            return false;
        }
        std::cout << "input 2 coordinates for 2 vertex\n";
        std::vector<std::pair<double, double>> tmp(4);
        std::string tmp1;
        std::cin >> tmp1;
        if (!IsCorrect(tmp1)){
            std::cout << "not correct input\n";
            return false;
        }
        tmp[0].first = atof(tmp1.c_str());
        std::cin >> tmp1;
        if (!IsCorrect(tmp1)){
            std::cout << "not correct input\n";
            return false;
        }
        tmp[0].second = atof(tmp1.c_str());
        std::cin >> tmp1;
        if (!IsCorrect(tmp1)){
            std::cout << "not correct input\n";
            return false;
        }
        tmp[2].first = atof(tmp1.c_str());
        std::cin >> tmp1;
        if (!IsCorrect(tmp1)){
            std::cout << "not correct input\n";
            return false;
        }
        tmp[2].second = atof(tmp1.c_str());
        tmp[1].first = tmp[0].first;
        tmp[1].second = tmp[2].second;
        tmp[3].first = tmp[2].first;
        tmp[3].second = tmp[0].second;
        Rectangle temp;
        temp.Set(tmp);
        Figure *fig1 = new Rectangle(temp);
        Figure *fig2 = new Rectangle(temp);
        figures.push_back(fig1);
        comand.push(std::make_pair("add", fig2));
        return true; 
    }
    bool AddTrapeze(){
        if (check_empty){
            std::cout << "document is empty\n";
            return false;
        }
        std::cout << "input 2 coordinats for 4 vertex\n";
        std::vector <std::pair<double, double>> tmp(4);
        std::string tmp1,tmp2;
        for (int i = 0; i < 4; i++){
            std::cin >> tmp1 >> tmp2;
            if (!IsCorrect(tmp1) || !IsCorrect(tmp2)){
                std::cout << "not correct input\n";
                return false;
            }
            tmp[i].first = atof(tmp1.c_str());
            tmp[i].second = atof(tmp2.c_str());
        }
        Trapeze temp;
        temp.Set(tmp);
        Figure *fig1 = new Trapeze(temp);
        Figure *fig2 = new Trapeze(temp);
        figures.push_back(fig1);
        comand.push(std::make_pair("add", fig2));
        return true;
    }
    bool AddRhomb(){
        if (check_empty){
            std::cout << "document is empty\n";
            return false;
        }
        std::cout << "input angle and side\n";
        std::vector <std::pair<double, double>> v(4);
        std::string tmp1,tmp2;
        double pi = M_PI, angle,side;
        std::cin >> tmp1 >> tmp2;
        if (!IsCorrect(tmp1) || !IsCorrect(tmp2)){
            std::cout << "not correct input\n";
            return false;
        }
        angle = atof(tmp1.c_str());
        side = atof(tmp2.c_str());
        v[0].first = 0;
        v[0].second = 0;
        if (angle <= 90 && side > 0){
            double alpha = (90 - angle) / 2;
            v[3].second = sin(alpha * pi / 180) * side;
            v[3].first = cos(alpha * pi / 180) * side;
            v[1].first = sin(alpha * pi / 180) * side;
            v[1].second = cos(alpha * pi / 180) * side;
            v[2].second = sin(alpha * pi / 180) * side + v[1].second;
            v[2].first = cos(alpha * pi / 180) * side + v[1].first;
        } else if (angle < 180 && side > 0) {
            double alpha = (270 - angle) / 2;
            v[3].second = cos(alpha * pi / 180) * side;
            v[3].first = sin(alpha * pi / 180) * side;
            v[1].first = cos(alpha * pi / 180) * side;
            v[1].second = sin(alpha * pi / 180) * side;
            double d = sqrt(2 * side * side - 2 * side * side * (cos((180 - alpha) * pi / 180)));
            v[2].first = cos(45 * pi / 180) * side;
            v[2].second  = cos(45 * pi / 180) * side;
        } else {
            std::cout << "wrong input\n";
            return false;
        }
        Rhomb temp;
        temp.Set(v);
        Figure *fig1 = new Rhomb(temp);
        Figure *fig2 = new Rhomb(temp);
        figures.push_back(fig1);
        comand.push(std::make_pair("add", fig2));
        return true;
    }
    bool RemoveFigure(){
        if (check_empty){
            std::cout << "document is empty\n";
            return false;
        }
        Figure *fig = figures[figures.size() - 1];
        figures.pop_back();
        comand.push(std::make_pair("rem", fig));
        return true;
    }
    void PrintDocument(){
        if (check_empty){
            std::cout << "document is empty\n";
            return;
        }
        for (auto fig : figures){
            std::cout << fig->GetName() << '\n';
            for (int i = 0; i < 4; i++){
                std::cout << fig->GetCoord()[i].first << " " << fig->GetCoord()[i].second << '\n';
            }
        }
    }
    bool UnDo(){
        if (comand.empty()){
            std::cout << "if firsts comand\n";
            return false;
        }
        if (comand.top().first == "add"){
            comand.pop();
            figures.pop_back();
            return true;
        }
        figures.push_back(comand.top().second);
        comand.pop();
        return true;
    }
    bool Load(std::string load_file){
        std::string tmp1,tmp2,tmp3,tmp4;
        std::ifstream ofile(load_file);
        figures.clear();
        if (comand.size() != 0){
            while (!comand.empty()){
                comand.pop();
            }
        }
        if (!ofile.is_open()){
            std::cout << "cant open file\n";
            return false;
        }
        ofile >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        if (check_empty){
            doc_name = tmp1;
            file_name = load_file;
            check_empty = true;
        }
        std::vector <std::pair <double, double>> cord(4);
        int n;
        ofile >> n;
        for (int i = 0; i < n; i++){
            ofile >> tmp1;
            for (int j = 0; j < 4; j++){
                ofile >> cord[j].first >> cord[j].second;
            }
            if (tmp1 == "rectangle"){
                Rectangle temp;
                temp.Set(cord);
                Figure *fig = new Rectangle(temp);
                figures.push_back(fig);
            } else if (tmp1 == "trapeze"){
                Trapeze temp;
                temp.Set(cord);
                Figure *fig = new Trapeze(temp);
                figures.push_back(fig);
            } else {
                Rhomb temp;
                temp.Set(cord);
                Figure *fig = new Rhomb(temp);
                figures.push_back(fig);
            }
        }
        ofile.close();
        return true;
    }
    void Show(){
        std::ofstream off;
        off.open("temp.txt");
        std::vector <std::pair < double, double>> tmp(4);
        for (auto fig : figures){
            tmp = fig->GetCoord();
            for (int j = 0; j < 4; j++){
                off << tmp[j].first << " " << tmp[j].second << " ";
            }
        }
        off.close();
        int status;
        int id = fork();
        if (id == 0){
            execl("testp.py", "testp.py", NULL);
        } else {
            waitpid(id, &status, 0);
            remove("temp.txt");
        }
    }
};

#endif