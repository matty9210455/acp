#include <iostream>
#include "classi.hpp"

using namespace std ;

void sparse_matrix::print(){
    MATRIX::iterator it=A.begin();
    MATRIX::iterator end=A.end();
    cout<<"numero righe "<<N_row<<" numero colonne "<<N_col<<endl;
    for(int i=0;i<N_row; i++){
        for (int j=0; j<N_col-1; j++){
            if(it<end){//check non sono fuori
                if((*it).get_row()==i && (*it).get_col()==j){
                  cout<<(*it).get_car()<<",";
                  it++;
                }else{
                cout<<0<<",";
                }
            }else{
                cout<<0<<",";
            }
         }
        if(it<end){//check non sono fuori
            if((*it).get_row()==i && (*it).get_col()==N_col-1){
              cout<<(*it).get_car()<<endl;
              it++;
            }else{
                cout<<0<<endl;
            }
        }else{
           cout<<0<<endl;
        }
    }
}
