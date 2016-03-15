#ifndef CLASSI_HPP
#define CLASSI_HPP

#include <vector>
#include<string>



class point{
private:
    int row;
    int col;
    int car;
public:
    point(int _row, int _col, int _car) : row(_row), col(_col), car(_car) {};
    int get_row(){return row;};
    int get_col(){return col;}
    int get_car(){return car;}
};

typedef std::vector<point> MATRIX;

class sparse_matrix{
private:
    MATRIX A;
    int N_row=0;
    int N_col=0;
public:
    sparse_matrix(std::string input);
};

#endif // CLASSI_HPP
