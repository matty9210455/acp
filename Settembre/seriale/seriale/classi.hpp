#ifndef CLASSI_HPP
#define CLASSI_HPP

#include<vector>
#include<string>

using namespace std;

struct point{
    int car;
    int row;
    int col;
    point(int _car, int _row, int _col) : car(_car), row(_row), col(_col) {};
};

class matrix{
private:
    vector<point> data;
    int N_row=0;
    int N_col=0;
public:
    void add_point(int car, int row, int col){
        point p(car,row,col);
        data.push_back(p);
    };

    matrix(string input);
    void print();
};
#endif // CLASSI_HPP
