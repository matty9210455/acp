#include <fstream>
using namespace std;
int main()
{
ofstream SaveFile("prova.csv");
SaveFile << "mattia.soprano@icloud.com"<<std::endl;
SaveFile<<"mattia.soprano@glive.it"<<std::endl;
SaveFile<<"mattia.soprano@mail.polimi.it"<<std::endl;
SaveFile.close();
return 0;
}
