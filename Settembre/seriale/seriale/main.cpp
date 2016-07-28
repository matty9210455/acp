#include <iostream>
#include<classi.hpp>

using namespace std;

int main()
{
    matrix A("problem.csv");
    cout<<"iterazione 0"<<endl;
    A.print();
    cout<<endl;
    for(int i=1;i<=10;i++){
        cout<<"iterazione "<<i<<endl;
        A.update();
        A.print();
        cout<<endl;
    }
    return 0;
}
