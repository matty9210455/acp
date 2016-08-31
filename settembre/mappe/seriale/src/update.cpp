#include<classi.hpp>
#include<vector>

using namespace std;

void matrix::update(int N_iter){
    for(size_t iter=0;iter<N_iter;iter++){
        vector<point_to_erase> erase;
        vector<point> add;
        auto last_row=data.end();
        if(move_blue){
            for(auto it_row=data.begin();it_row!=last_row;it_row++){
                auto next_row=data.find(it_row->first+1);
                if(it_row->first==N_row-1) {next_row=data.find(0);}
                if(next_row!=last_row){
                    auto last_point=it_row->second.end();
                    auto last_nextRow_point=next_row->second.end();
                    for(auto it=it_row->second.begin();it!=last_point;it++){
                        if(it->second==1){
                            auto aux=next_row->second.find(it->first);
                            if(aux==last_nextRow_point){
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
                for(auto it=it_row->second.begin();it!=last_point;it++){
                    if(it->second==2){
                        auto aux=it_row->second.find(it->first+1);
                        if(it->first==N_col-1){aux=it_row->second.find(0);}
                        if(aux==last_point){
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

    }
}
