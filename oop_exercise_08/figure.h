#ifndef FIGURE_H
#define FIGURE_H

class Figure{
    public:
    virtual void Set (std::vector <std::pair<double,double>> cord) = 0;
    virtual std::string GetName() = 0;
    virtual std::vector<std::pair<double, double>> GetCoord() = 0;
    virtual void Print() = 0;
};

#endif