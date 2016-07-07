#include <iostream>
#include"classi.hpp"
#include<fstream>
#include<stdlib.h>

using namespace std;

int main()
{
    MATRIX data("problem.csv");

    vector<int> iteration;
     //iterazioni

    int value;

    //apertura e controllo file
    string input("problem.csv");
    ifstream f(input);
    string s;
    if(!f){//check file giusto

            cout<<"file non esiste"<<endl;
            return 0;
    }

    //numero iterazioni
    getline(f,s);
    for(auto it=s.begin();it<s.end();it++){//iterazioni
            value=atoi(&(*it));
            iteration.push_back(value);
            while((*it)!=','&& it<s.end()) it++;
    }
    f.close();
    int i=0;
    auto N=iteration.size();
    for(auto j=0;j<N;j++){
        int N_it=iteration[j];
        while (i<N_it){
            data.update();
            i++;
        }
        data.print(i);
    }

    return 0;
}
