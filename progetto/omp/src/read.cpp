
#include"classi.hpp"
#include<fstream>
#include<stdlib.h>
#include<iostream>

using namespace std;

MATRIX::MATRIX(string input){

    string s;
    ifstream f(input);

    //check file giusto
    if(!f){
        cout<<"file non esiste"<<endl;
        exit(1);
    }

    getline(f,s); //salto riga delle iterazioni

    int col(0); //indice colonna che sto leggendo
    int row(0); //indice riga che sto leggendo
    int value(0);
    bool first_el=true;

    //prima riga

    getline(f,s);
    vector<ROW>::iterator last_row;
    for(auto it=s.begin();it<s.end();it++){

        value=atoi(&(*it));
        if(value==1 || value==2){
            POINT p(col, value);

            if(first_el){
               ROW r(row,p);
               data.push_back(r);
               last_row=--data.end();
               first_el=false;
            }else{
               last_row->push_back(p);
            }

        }else{
           if(value!=0){
                cout<<"dato anomalo "<<value<<endl;
                exit(1);
           }
        }

        col=col+1;//indice colonna
        it++; //vado su virgola
    }

    row++;
    N_col=col;
    N_row=row;

    //altre righe
    while(getline(f,s)){
        col=0;
        first_el=true;
        for(auto it=s.begin();it<s.end();it++){
            value=atoi(&(*it));
            if(value==1 || value==2){
                POINT p(col,value);
                if(first_el){
                    ROW r(row,p);
                    data.push_back(r);
                    first_el=false;
                    last_row=--data.end();
                }else{
                    last_row->push_back(p);
                }
            }else{
           if(value!=0){
                cout<<"dato anomalo "<<value<<endl;
                exit(1);
           }
        }

        col=col+1;//indice colonna
        it++; //vado su virgola
    }

    if(N_col!=col){
        cout<<"numeri di elementi letti irregolare"<<endl;
        cout<<"numeri aspettati "<<N_col<<" numeri letti "<<col<<endl;
        exit(1);
    }

    row++;
    N_row=row;
}
f.close();

}

