#include <iostream>
#include"classi.hpp"

using namespace std;

int main()
{
    MATRIX data("problem.csv");
    int i=0;
    while (i<1){
    data.update();
            i++;
    }
    cout<<"iterazione "<<i<<endl;
    data.print();
    data.print(i);
    while (i<10){
    data.update();
    i++;
    }
    cout<<"iterazione "<<i<<endl;
    data.print();
    data.print(i);
    while (i<100){
    data.update();
    i++;
    }
    cout<<"iterazione "<<i<<endl;
    data.print();
    data.print(i);
    return 0;
}
