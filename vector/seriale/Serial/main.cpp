#include <iostream>
#include"class.hpp"

using namespace std;

int main()
{
    MATRIX DATA("problem.csv");
    DATA.update(2);
    DATA.print();
    return 0;
}
