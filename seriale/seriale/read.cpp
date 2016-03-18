#include "classi.hpp"
#include<fstream>
#include<stdlib.h>
#include<iostream>

using namespace std;

sparse_matrix::sparse_matrix(string input){

    string s;
    ifstream f(input);

    if(!f){//check file giusto

        cout<<"file non esiste"<<endl;
        exit(1);
    }

    getline(f,s); //salto riga delle iterazioni

    int col(0); //indice colonna che sto leggendo
    int row(0); //indice riga che sto leggendo
    int value(0);

    //prima riga
    getline(f,s);
    bool first=true;
    MATRIX::iterator last_row ;
    for(auto it=s.begin();it<s.end();it++){
        value=atoi(&(*it));
        ROW::iterator last_el;
        if(value==1 || value==2){
           if(first){
               ROW aux;
               aux.insert(make_pair(col,value));
               A.insert(make_pair(row,aux));
               last_row=A.end();
               last_row--;
               first=false;
           }else{
           last_row->second.insert(make_pair(col,value));
           }
        }else{
           if(value!=0){
                cout<<"dato anomalo"<<endl;
                exit(1);
           }
        }

        col=col+1;//indice colonna
        it++; //vado su virgola
    }

    N_col=col;
    N_row=1;

    //altre righe
    while(getline(f,s)){
        row=row+1;
        col=0;
        first=true;
        for(auto it=s.begin();it<s.end();it++){
            value=atoi(&(*it));
            if(value==1 || value==2){
                if(first){
                    ROW aux;
                    aux.insert(make_pair(col,value));
                    A.insert(make_pair(row,aux));
                    last_row=A.end();
                    last_row--;
                    first=false;
                }else{
                    last_row->second.insert(make_pair(col,value));
                }
            }else{
               if(value!=0){
                    cout<<"dato anomalo"<<endl;
                    exit(1);
               }
            }

            col=col+1;//indice colonna
            it++; //vado su virgola
        }
            if(col!=N_col){
                cout<<"numero di colonne sbagliato: colonne lette "<<col<<", colonne attese "<<N_col<<endl;
                exit(1);
            }

        col=0;
        N_row=row+1;
}
f.close();

};
