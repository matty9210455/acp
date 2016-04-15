#ifndef CLASS_HPP
#define CLASS_HPP

#include<vector>
#include<string>
#include<map>

struct POINT{
    int col;
    int car;
    POINT(int _col, int _car);
};

typedef typename std::vector<POINT>::iterator ROW_iterator ;

class ROW{
private:
    std::vector<POINT> _row;
public:
    ROW(POINT p);
    void push_back(POINT p){_row.push_back(p);};
    ROW_iterator begin(){return _row.begin();};
    ROW_iterator end() {return _row.end();};
    void add_element_front(int col, int car);
    void erase(ROW_iterator p){_row.erase(p);}
};



class MATRIX{
private:
    std::map<int, ROW> data;
    int N_row;
    int N_col;
    bool move_blue=true;
public:
    MATRIX(std::string input);
    void print();
    void update(int iteraction);
};

#endif // CLASS_HPP
