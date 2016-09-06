#include<classi.hpp>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

void matrix::print(){
    auto fine_righe=data.end();
    for(size_t i=0;i<N_row;i++){
        auto aux_row=data.find(i);
        if(aux_row!=fine_righe){
            auto fine_col=data[i].end();
            for(size_t j=0;j<N_col-1;j++){
                auto aux_col=data[i].find(j);
                if(aux_col!=fine_col){
                    cout<<aux_col->second<<",";
                }else{
                cout<<0<<",";
                }
            }
            auto aux_col=data[i].find(N_col-1);
            if(aux_col!=fine_col){
                cout<<aux_col->second<<endl;
            }else{
            cout<<0<<endl;
            }
        }else{
            for(size_t j=0;j<N_col-1;j++){
                cout<<0<<",";
            }
            cout<<0<<endl;
        }
    }
    cout<<endl;
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

        auto fine_righe=data.end();
        for(size_t i=0;i<N_row;i++){
            auto aux_row=data.find(i);
            if(aux_row!=fine_righe){
                auto fine_col=data[i].end();
                for(size_t j=0;j<N_col-1;j++){
                    auto aux_col=data[i].find(j);
                    if(aux_col!=fine_col){
                        out<<aux_col->second<<",";
                    }else{
                    out<<0<<",";
                    }
                }
                auto aux_col=data[i].find(N_col-1);
                if(aux_col!=fine_col){
                    out<<aux_col->second<<endl;
                }else{
                out<<0<<endl;
                }
            }else{
                for(size_t j=0;j<N_col-1;j++){
                    out<<0<<",";
                }
                out<<0<<endl;
            }
        }
}
