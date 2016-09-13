#include<classi.hpp>
#include<vector>
#include<iostream>

using namespace std;

void matrix::update(int N_iter){
    for(size_t iter=0;iter<N_iter;iter++){
        vector<point_to_erase> erase;
        vector<point> add;
        auto last_row=data.end();
        auto next_row=data.begin();
        if(move_blue){
            for(auto it_row=data.begin(); it_row!=last_row; it_row++){
                /*auto next_row=data.find(it_row->first+1);
                if(it_row->first==N_row-1) {next_row=data.find(0);}
                if(next_row!=last_row)*/
                next_row++;
                if(it_row->first==N_row-1){next_row=data.begin();}
                    if( (it_row->first+1==next_row->first || (it_row->first==N_row-1 && next_row->first==0) ) && next_row!=last_row){
                    auto last_point=it_row->second.end();
                    auto last_nextRow_point=next_row->second.end();
                    auto pointNextRow=next_row->second.begin();
                    for(auto it=it_row->second.begin();it!=last_point;it++){
                        if(it->second==1){
                            while(pointNextRow!=last_nextRow_point && it->first > pointNextRow->first){pointNextRow++;}
                            if(pointNextRow->first!=it->first || pointNextRow==last_nextRow_point ){
                                point aux_add(it_row->first+1,it->first,1);
                                if(aux_add.row==N_row){aux_add.row=0;}
                                add.push_back(aux_add);
                                point_to_erase aux_er(it_row,it);
                                erase.push_back(aux_er);
                            }
                        }
                    }
                }else{
                    auto last_point=it_row->second.end();
                    for(auto it=it_row->second.begin();it!=last_point;it++){
                        if(it->second==1){
                                point aux_add(it_row->first+1,it->first,1);
                                if(aux_add.row==N_row){aux_add.row=0;}
                                add.push_back(aux_add);
                                point_to_erase aux_er(it_row,it);
                                erase.push_back(aux_er);
                        }
                    }
                }
            }
            move_blue=false;
        }else{
            for(auto it_row=data.begin();it_row!=last_row;it_row++){
                auto last_point=it_row->second.end();
                auto nextPoint=it_row->second.begin();
                for(auto it=it_row->second.begin();it!=last_point;it++){
                    nextPoint++;
                    if(it->first==N_col-1){nextPoint=it_row->second.begin();}
                    if(it->second==2){
                        if( (nextPoint==last_point) || ( (nextPoint->first!=it->first+1 && it->first!=N_col-1) || (it->first==N_col-1 && nextPoint->first!=0) ) ){
                            point aux_add(it_row->first,it->first+1,2);
                            if(aux_add.col==N_col){aux_add.col=0;}
                            add.push_back(aux_add);
                            point_to_erase aux_er(it_row,it);
                            erase.push_back(aux_er);
                        }
                    }
                }
            }
            move_blue=true;
        }

        //erase

        auto N_change=erase.size();
        for(size_t i=0;i<N_change;i++){
            erase[i].row->second.erase(erase[i].col);
        }

        //add

        for(size_t i_add=0;i_add<add.size();i_add++){
            data[add[i_add].row][add[i_add].col]=add[i_add].car;
        }
        
        auto it_row=data.begin();
        while (it_row!=last_row) {
            if(it_row->second.size ()==0){
                auto aux=it_row;
                it_row++;
                data.erase(aux);
            }else{
                it_row++;
            }
        }
    }
}
