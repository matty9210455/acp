#include<classi.hpp>
#include<iostream>
#include<algorithm>

using namespace std;


bool ComparePoint(point const & p1, point const & p2){
    if(p1.row<p2.row){
        return true;
    }else{
        if(p1.col<p2.col){
            return true;
        }
    };
    return false;
};


void matrix::update(int iteration){
    auto N=data.size();
    for(auto iter=0;iter<iteration;iter++){
        if(move_blue){
            auto it=data.begin();
            auto fine=data.end();
            vector<vector<point>::iterator> erase;
            vector<point> add;
            //controllo
            for(size_t i=0;i<N;i++){
                if(data[i].car==1){
                    point p=data[i];
                    point aux(1,p.row+1,p.col);
                    if(p.row==N_row-1){ aux.row=0;}
                    it=lower_bound(it,fine,aux,ComparePoint);
                    if(it->col!=p.col && it!=fine){
                        add.push_back(aux);
                        erase.push_back(it);
                        cout<<it->row<< " "<<it->col<< " eliminazione"<<endl;                    }
                }
            }

            //cancellazzione
            auto N_change=erase.size();
            for(int i=N_change-1;i>=0;i--){
                data.erase(erase[i]);

            };
            //aggiunta
            it=data.begin();
            bool first=true;
            for(size_t i_add=0;i_add<N_change;i_add++){
                auto p=add[i_add];
                if(p.row==0 && first){
                        it=data.begin();
                        first=false;
                }
                it=lower_bound(it,fine,p,ComparePoint );
                data.insert(it,p);
            }
            //cambio
            //move_blue=false;
        }
    }
}

