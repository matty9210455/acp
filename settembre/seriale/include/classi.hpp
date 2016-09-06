#ifndef CLASSI_HPP
#define CLASSI_HPP

#include<map>

struct point{
    int row;
    int col;
    int car;
public:
    point(int _row, int _col, int _car) : car(_car), row(_row), col(_col) {};
};

typedef typename std::map<int,std::map<int,int> >::iterator iterator_row;
typedef typename std::map<int,int>::iterator iterator_point;

struct point_to_erase{
    iterator_row row;
    iterator_point col;
    /*int row;
    int col;*/
public:
    point_to_erase( iterator_row _row, iterator_point _col ) :  row(_row), col(_col) {};
};

class matrix{
private:
    std::map<int,std::map<int,int> > data;
    bool move_blue=true;
    int N_row;
    int N_col;
public:
    matrix(std::string input);
    void print();
    void update(int N_iter);
    void print(int iteration);

};

#endif // CLASSI_HPP
