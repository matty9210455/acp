#include <iostream>
#include<classi.hpp>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main()
{
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

    int j=0;
    auto N=iteration.size();
    for(size_t i=0;i<N;i++){
        int N_it=iteration[i];
        while(j<N_it){

            A.update();
            j++;
        }
        A.print(j);

    }/*

    int N=15;
    for(int j=1;j<=N;j++){
        cout<<"iterazione "<<j<<endl;

        //cout<<"update"<<endl;

        A.update();
        A.print();
        cout<<endl;
    }
    //cout<<"iterazione "<<N<<endl;
    A.print();
    cout<<endl;*/

    return 0;
}
