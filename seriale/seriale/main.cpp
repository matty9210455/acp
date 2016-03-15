#include <iostream>
#include "classi.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    point a(5,6,1);
    cout << a.get_row()<<" "<<a.get_col()<<" "<<a.get_car() << endl;
    return 0;
}
