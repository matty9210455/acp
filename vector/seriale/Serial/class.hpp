#ifndef CLASS_HPP
#define CLASS_HPP

#include<vector>
#include<string>

struct POINT{
    int col;
    int car;
    POINT(int _col, int _car);
};

typedef typename std::vector<POINT>::iterator ROW_iterator ;

class ROW{
private:
    std::vector<POINT> _row;
    int n_row;
public:
    ROW(POINT p, int _n_row);
    void add_element(POINT p){_row.push_back(p);};
    int Get_n_row(){return n_row;}
    ROW_iterator begin(){return _row.begin();};
    ROW_iterator end() {return _row.end();};
};

typedef typename std::vector< ROW >::iterator MATRIX_iterator ;

class MATRIX{
private:
    std::vector<ROW> data;
    int N_row;
    int N_col;
    bool move_blue=true;
public:
    MATRIX(std::string input);
    void print();
};

#endif // CLASS_HPP
