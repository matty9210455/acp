#include<classi.hpp>
#include<iostream>

using namespace std;

void matrix::print(){
    auto p=data.begin();
    cout<<"numero di righe "<<N_row<<" numero di colonne "<<N_col<<endl;
    for (auto i=0; i<N_row;i++){
        for(auto j=0; j<N_col-1;j++){
            if(p->row==i && p->col==j){
                cout<<p->car<<",";
                p++;
            }else{
                cout<<0<<",";
            }
        }
        if(p->row==i && p->col==N_col-1){
            cout<<p->car<<endl;
            p++;
        }else{
            cout<<0<<endl;
        }
    }
}
