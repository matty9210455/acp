#include<class.hpp>
#include<fstream>
#include<stdlib.h>
#include<iostream>

using namespace std;

POINT::POINT(int _col, int _car){
    col=_col;
    car=_car;
}

ROW::ROW(POINT p, int _n_row){
    _row.push_back(p);
    n_row=_n_row;
}

MATRIX::MATRIX(string input){

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
    bool first_el=true;

    //prima riga

    getline(f,s);

    for(auto it=s.begin();it<s.end();it++){

        value=atoi(&(*it));
        if(value==1 || value==2){
            POINT aux_p(col, value);

            if(first_el){
               ROW aux_r(aux_p, row);
               data.push_back(aux_r);
               first_el=false;

            }else{
               (--data.end())->push_back(aux_p);
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

    row++;
    N_col=col;
    N_row=row;

    //altre righe
    while(getline(f,s)){
        col=0;
        for(auto it=s.begin();it<s.end();it++){
            value=atoi(&(*it));
            if(value==1 || value==2){
                POINT aux_p(col, value);

                if(first_el){
               ROW aux_r(aux_p, row);
               data.push_back(aux_r);
               first_el=false;
                }else{
                    auto last_row=--data.end();
                if(last_row->Get_n_row()==row){
                   (last_row)->push_back(aux_p);
               }else{
                   ROW aux_r(aux_p, row);
                   data.push_back(aux_r);
               }

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
