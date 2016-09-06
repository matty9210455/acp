#include<classi.hpp>
#include<iostream>
#include<algorithm>

using namespace std;


bool ComparePoint(point const & p1, point const & p2){//torna vero se p1 e dietro p2
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
            cout<<endl<<"blu"<<endl;
            auto fine=data.end();
            vector<vector<point>::iterator> erase;
            vector<point> add;

//controllo

            auto p=data.begin();
            while(p!=fine && p->row<N_row-1){
                if(p->car==1){
                    point aux(1,p->row+1,p->col);
                    if(!binary_search(p,fine,aux,ComparePoint)){
                        add.push_back(aux);
                        erase.push_back(p);
                    }
                }
                p++;
            }

            auto it_aux=data.begin();
            int add_first_row=0;
            while(p!=fine){
                if(p->car==1){
                    point aux(1,0,p->col);
                    if(!binary_search(it_aux,fine,aux,ComparePoint)){
                        erase.push_back(p);
                        add.insert(add.begin()+add_first_row,aux);
                        add_first_row++;
                    }
                }
                p++;
            }

            //cancellazzione

            /*cout<<"matrice pre update"<<endl;
            for(auto print=data.begin();print!=data.end();print++){
              cout<<"righe "<<(print)->row<<" colonne "<<(print)->col<<" macchina "<<(print)->car<<endl;
            }*/
            auto N_change=erase.size();

            /*cout<<"cancellazione"<<endl;
            for(auto print=erase.begin();print!=erase.end();print++){
              cout<<"righe "<<(*print)->row<<" colonne "<<(*print)->col<<" macchina "<<(*print)->car<<endl;
            }*/

            for(int i=N_change-1;i>=0;i--){
                data.erase(erase[i]);
            };

           //aggiunta

           /* cout<<"aggiunta"<<endl;
            for(auto print=add.begin();print!=add.end();print++){
              cout<<"righe "<<(print)->row<<" colonne "<<(print)->col<<" macchina "<<(print)->car<<endl;
            }*/

            int j=0;
            int N_point=data.size();
            for(size_t i_add=0;i_add<N_change;i_add++){
                bool insert=true;
                while(j<N_point && insert){
                    if(ComparePoint(add[i_add],data[j])){
                        auto it=data.begin();
                        data.insert(it+j,add[i_add]);
                        N_point++;
                        insert=false;
                    }
                    j++;
                }
                if(j==N_point && insert){
                    data.push_back(add[i_add]);
                }
           }

           /* cout<<"matrice post update"<<endl;
            for(auto print=data.begin();print!=data.end();print++){
              cout<<"righe "<<(print)->row<<" colonne "<<(print)->col<<" macchina "<<(print)->car<<endl;
            }*/

            //cambio
            move_blue=false;
        }else{
            cout<<endl<<"rosse"<<endl;
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

            /*for(auto print=erase.begin();print!=erase.end();print++){
              cout<<"righe "<<(*print)->row<<" colonne "<<(*print)->col<<" macchina "<<(*print)->car<<endl;
            }*/

            for(int i=N_change-1;i>=0;i--){
                data.erase(erase[i]);
            };

           //aggiunta

            /*for(auto print=add.begin();print!=add.end();print++){
              cout<<"righe "<<(print)->row<<" colonne "<<(print)->col<<" macchina "<<(print)->car<<endl;
            }*/

            int j=0;
            int N_point=data.size();
            for(size_t i_add=0;i_add<N_change;i_add++){
                bool insert=true;
                while(j<N_point && insert){
                    if(ComparePoint(add[i_add],data[j])){
                        auto it=data.begin();
                        data.insert(it+j,add[i_add]);
                        N_point++;
                        insert=false;
                    }
                    j++;
                }
                if(j==N_point && insert){
                    data.push_back(add[i_add]);
                }
           }

            move_blue=true;
        }
}

