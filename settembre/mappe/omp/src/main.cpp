#include <iostream>
#include<classi.hpp>
#include<fstream>
#include<stdlib.h>
#include<vector>

using namespace std;

int main(){
    matrix A("problem.csv");

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

    A.print();

    auto N=iteration.size();
    auto old=0;
    for(size_t i=0; i<N;i++){
        A.update(iteration[i]-old);
        A.print(iteration[i]);
        old=iteration[i];
    }

    return 0;
}

