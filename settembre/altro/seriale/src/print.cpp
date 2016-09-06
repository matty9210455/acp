#include<classi.hpp>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

void matrix::print(){
    auto p=data.begin();
    //cout<<"numero di righe "<<N_row<<" numero di colonne "<<N_col<<" numero di elementi "<<data.size()<<endl;
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



void matrix::print(int iteration){
    string output;
        stringstream convert;
        convert<<iteration;
        output=convert.str();
        output.push_back('.');
        output.push_back('c');
        output.push_back('s');
        output.push_back('v');
        ofstream out;
        out.open(output,ios::trunc);
        auto p=data.begin();

        for (auto i=0; i<N_row;i++){
            for(auto j=0; j<N_col-1;j++){
                if(p->row==i && p->col==j){
                    out<<p->car<<",";
                    p++;
                }else{
                    out<<0<<",";
                }
            }
            if(p->row==i && p->col==N_col-1){
                out<<p->car<<endl;
                p++;
            }else{
                out<<0<<endl;
            }
        }
}
