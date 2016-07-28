#ifndef CLASSI_HPP
#define CLASSI_HPP

#include<vector>
#include<string>



struct point{
    int car;
    int row;
    int col;
    point(int _car, int _row, int _col) : car(_car), row(_row), col(_col) {};
};

class matrix{
private:
    std::vector<point> data;
    int N_row=0;
    int N_col=0;
    bool move_blue=true;
public:
    void add_point(int car, int row, int col){
        point p(car,row,col);
        data.push_back(p);
    };

    matrix(std::string input);
    void print();
    void update();
    void print(int iteration);
};
#endif // CLASSI_HPP
