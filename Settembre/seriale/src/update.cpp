#include<classi.hpp>
#include<iostream>
#include<algorithm>

using namespace std;


bool ComparePoint(point const & p1, point const & p2){
    if(p1.row<p2.row){
        return true;
    }else{
        if(p1.row>p2.row) {return false;}
        if(p1.col<p2.col){
            return true;
        }
    };
    return false;
};


void matrix::update(){
        if(move_blue){
            auto fine=data.end();
            vector<vector<point>::iterator> erase;
            vector<point> add;

            //controllo
            for(auto p=data.begin();p!=fine;p++){
                if(p->car==1){
                    point punto=(*p);
                    point aux(1,punto.row+1,punto.col);
                    if(punto.row==N_row-1){
                        aux.row=0;
                    }
                    if(!binary_search(p,fine,aux,ComparePoint)){
                        add.push_back(aux);
                        erase.push_back(p);
                        }
                }
            }

            //cancellazzione
            auto N_change=erase.size();
            for(int i=N_change-1;i>=0;i--){
                data.erase(erase[i]);
            };

            //aggiunta

            auto it=data.begin();
            bool first=true;
            for(size_t i_add=0;i_add<N_change;i_add++){
                auto p=add[i_add];

                if(p.row==0 && first){
                        it=data.begin();
                        first=false;
                }

                it=lower_bound(it,fine,p,ComparePoint);

                if(it==fine){
                    data.push_back(p);
                    it=data.end()--;
                    fine=data.end();
                }else{
                    data.insert(it,p);
                    fine=data.end();
                }
            }

            //cambio
            move_blue=false;
        }else{
            auto fine=data.end();
            vector<point> add;
            vector<vector<point>::iterator> erase;
            auto it=data.begin();
            int row=-1;
            for(auto next_point=++data.begin();next_point!=fine;next_point++){

                if(it->car==2){

                    if(it->col==0){
                        row=it->row;
                    }

                    if(it->col==N_col-1){

                        if(it->row!=row){
                            point aux(2,it->row,0);
                            add.push_back(aux);
                            erase.push_back(it);
                        };

                    }else{
                        if(it->col!=next_point->col-1 || it->row!=next_point->row){
                            it->col=it->col+1;
                        }
                    }
                }
                it++;
            }
            //ULTIMO PUNTO//
            if(it->car==2){

                if(it->col==N_col-1){
                    if(it->row!=row){
                        point aux(2,it->row,0);
                        add.push_back(aux);
                        erase.push_back(it);
                    };

                }else{
                    it->col=it->col+1;
                }
            }

            //cancellazzione
            auto N_change=erase.size();
            for(int i=N_change-1;i>=0;i--){
                data.erase(erase[i]);
            };

            //aggiunta

            it=data.begin();
            fine=data.end();
            for(size_t i_add=0;i_add<N_change;i_add++){
                auto p=add[i_add];

                it=lower_bound(it,fine,p,ComparePoint);

                if(it==fine){
                    data.push_back(p);
                    it=data.end()--;
                    fine=data.end();
                }else{
                    data.insert(it,p);
                    fine=data.end();
                }
            }

            move_blue=true;
        }
}

