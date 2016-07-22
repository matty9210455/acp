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


void matrix::update(int iteration){
    for(auto iter=0;iter<iteration;iter++){
        if(move_blue){
            auto start=data.begin();
            auto fine=data.end();
            vector<vector<point>::iterator> erase;
            vector<point> add;
            int dim=sizeof(point);
            //controllo
            for(auto p=data.begin();p!=fine;p++){
                if(p->car==1){
                    point punto=(*p);
                    point aux(1,punto.row+1,punto.col);
                    if(punto.row==N_row-1){
                        aux.row=0;}
                    else{
                        if(!binary_search(p,fine,aux,ComparePoint)){
                        add.push_back(aux);
                        erase.push_back(p);
                        }
                    }
                }
            }

            //cancellazzione
            auto N_change=erase.size();
            for(int i=N_change-1;i>=0;i--){
                cout<<"cancellazione "<<i<<" su "<<N_change<<endl;
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
                it=lower_bound(it,fine,p,ComparePoint );
                data.insert(it,p);
            }
            //cambio
            //move_blue=false;
        }
    }
}

