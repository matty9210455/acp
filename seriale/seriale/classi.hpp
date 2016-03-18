#ifndef CLASSI_HPP
#define CLASSI_HPP


#include<string>
#include<map>

typedef typename std::map<int,int> ROW;

typedef typename std::map<int,ROW> MATRIX;

class sparse_matrix{
private:
    MATRIX A;
    int N_row=0;
    int N_col=0;
public:
    sparse_matrix(std::string input);
    void print();
};

#endif // CLASSI_HPP
