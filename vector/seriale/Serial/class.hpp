#ifndef CLASS_HPP
#define CLASS_HPP

#include<vector>
#include<string>
#include<map>

struct POINT{
    int col;
    int car;
    POINT(int _col, int _car);
    void up_red(int N_col){
        if (col<N_col-1) col=col+1;
        else col=0;
    }
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
    int size(){return _row.size();}
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
    void erase(std::map<int,ROW>::iterator aux){data.erase(aux);}
};

#endif // CLASS_HPP
