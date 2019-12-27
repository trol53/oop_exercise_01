#ifndef INPUT_H
#define INPUT_H

bool IsCorrect(std::string check){
    for (int i = 0; i < check.size(); i++){
        if (check[i] < '0' || check[i] > '9'){
            return false;
        }
    }
    return true;
}

void AddRectangle(std::vector <Figure*> &buffer){
        std::cout << "input 2 coordinates for 2 vertex\n";
        std::vector<std::pair<double, double>> tmp(4);
        std::string tmp1;
        std::cin >> tmp1;
        if (!IsCorrect(tmp1)){
            std::cout << "not correct input\n";
            return;
        }
        tmp[0].first = atof(tmp1.c_str());
        std::cin >> tmp1;
        if (!IsCorrect(tmp1)){
            std::cout << "not correct input\n";
            return;
        }
        tmp[0].second = atof(tmp1.c_str());
        std::cin >> tmp1;
        if (!IsCorrect(tmp1)){
            std::cout << "not correct input\n";
            return;
        }
        tmp[2].first = atof(tmp1.c_str());
        std::cin >> tmp1;
        if (!IsCorrect(tmp1)){
            std::cout << "not correct input\n";
            return;
        }
        tmp[2].second = atof(tmp1.c_str());
        tmp[1].first = tmp[0].first;
        tmp[1].second = tmp[2].second;
        tmp[3].first = tmp[2].first;
        tmp[3].second = tmp[0].second;
        Rectangle temp;
        temp.Set(tmp);
        Figure *fig1 = new Rectangle(temp);
        buffer.push_back(fig1);
}
void AddTrapeze(std::vector <Figure*> &buffer){
        std::cout << "input 2 coordinats for 4 vertex\n";
        std::vector <std::pair<double, double>> tmp(4);
        std::string tmp1,tmp2;
        for (int i = 0; i < 4; i++){
            std::cin >> tmp1 >> tmp2;
            if (!IsCorrect(tmp1) || !IsCorrect(tmp2)){
                std::cout << "not correct input\n";
                return;
            }
            tmp[i].first = atof(tmp1.c_str());
            tmp[i].second = atof(tmp2.c_str());
        }
        Trapeze temp;
        temp.Set(tmp);
        Figure *fig1 = new Trapeze(temp);
        Figure *fig2 = new Trapeze(temp);
        buffer.push_back(fig1);
}

void AddRhomb(std::vector <Figure*> &buffer){
        std::cout << "input angle and side\n";
        std::vector <std::pair<double, double>> v(4);
        std::string tmp1,tmp2;
        double pi = M_PI, angle,side;
        std::cin >> tmp1 >> tmp2;
        if (!IsCorrect(tmp1) || !IsCorrect(tmp2)){
            std::cout << "not correct input\n";
            return;
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
            return;
        }
        Rhomb temp;
        temp.Set(v);
        Figure *fig1 = new Rhomb(temp);
        Figure *fig2 = new Rhomb(temp);
        buffer.push_back(fig1);
}

#endif