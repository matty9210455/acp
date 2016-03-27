#ifndef CLASSI_HPP
#define CLASSI_HPP


#include<string>
#include<map>

typedef typename std::map<int,int> ROW; // primo int colonna secondo int macchina

typedef typename std::map<int,ROW> MATRIX; //primo int riga secondo tutta la riga

class sparse_matrix{
private:
    MATRIX A;
    int N_row=0;
    int N_col=0;
    bool move_blue=true;
public:
    sparse_matrix(std::string input);
    void print();
    void update(int N_iteration);
};

#endif // CLASSI_HPP
