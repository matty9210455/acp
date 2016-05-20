#include<iostream>
#include<classi.hpp>

using namespace std;

void MATRIX::print(){
    auto row=data.begin();
    auto const last_row=data.end();
    for(int i=0; i<N_row; i++){
        if(row->get_nrow()==i && row!=last_row){
            auto point=row->begin();
            auto const last_point=row->end();
            for(int j=0;j<N_col-1;j++){
                if(j==point->col && point!=last_point){
                    cout<<point->car<<",";
                    point++;
                }else{
                    cout<<0<<",";
                }
            }
            int j=N_col-1;
            if(j==point->col){
                cout<<point->car<<endl;
            }else{
                cout<<0<<endl;
            }
            row++;
        }else{
            for(int j=0;j<N_col-1; j++){
                cout<<"0,";
            }
            cout<<"0"<<endl;
        }
    }
}
