#include <iostream>
#include"classi.hpp"

using namespace std;

int main()
{
    MATRIX data("problem.csv");
    data.print();
    data.update(3);
    cout<<"stampa dopo 3 iterazioni"<<endl;
    data.print();
    return 0;
}
