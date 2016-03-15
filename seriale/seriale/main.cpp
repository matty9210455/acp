#include <iostream>
#include "classi.hpp"

using namespace std;

int main()
{
    sparse_matrix DATA("problem.csv");
    DATA.print();
    return 0;
}
