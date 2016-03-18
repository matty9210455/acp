#include <iostream>
#include "classi.hpp"

using namespace std ;

void sparse_matrix::print(){
    MATRIX::iterator it_row=A.begin();
    MATRIX::iterator end_row=A.end();
    cout<<"numero righe "<<N_row<<" numero colonne "<<N_col<<endl;
    for(int i=0;i<N_row; i++){
        if(it_row!=end_row && it_row->first==i){
            ROW::iterator it_col=it_row->second.begin();
            ROW::iterator end_col=it_row->second.end();
            for(int j=0; j<N_col-1; j++){
                if(it_col!=end_col && it_col->first==j){
                    cout<<it_col->second<<",";
                    it_col++;
                }else{
                    cout<<0<<",";
                }
            }
            if(it_col!=end_col && it_col->first==N_col-1){
                cout<<it_col->second<<endl;
            }else{
                cout<<0<<endl;
            }
            it_row++;
        }else{
            for(int j=0;j<N_col-1;j++){
                cout<<0<<",";
            }
            cout<<0<<endl;
        }
    }
}

