#include"classi.hpp"
#include<iostream>
#include<vector>
#include<algorithm>
#include<omp.h>
using namespace std;

bool compare_POINT(POINT const & p1, POINT const & p2){ return p1.col<p2.col; }

bool compare_ROW(ROW const & r1, ROW const & r2){return r1.get_nrow() < r2.get_nrow();}

void UpdateBlueRow(ROW & row, ROW & next_row, ROW & add){

    add.change_nrow(row.get_nrow()+1);
    auto p=row.begin();
    auto p_next_row=next_row.begin();
    auto last_p=row.end();
    auto last_p_next_row=next_row.end();
    vector<vector<POINT>::iterator> erase;

    if(row.get_nrow()==next_row.get_nrow()-1){
        while(p!=last_p){
            if(p->car==1){
                while(p->col>p_next_row->col && p_next_row!=last_p_next_row){
                    p_next_row++;
                }
                if(p_next_row==last_p_next_row || p->col!=p_next_row->col){
                    POINT aux(p->col,1);
                    add.push_back(aux);
                    erase.push_back(p);
                }
            }
            p++;
        }
    }else{
        while(p!=last_p){
            if(p->car==1){
                POINT aux(p->col,1);
                add.push_back(aux);
                erase.push_back(p);
            }
            p++;
        }
    }
    int N=erase.size();
    if(N>0){
        add.change_nrow(row.get_nrow()+1);
        for(int i=N-1;i>=0;i--){
            row.erase(erase[i]);
        }
    }


}

void UpdateLastBlueRow(ROW & row, ROW & next_row, ROW & add, vector<vector<POINT>::iterator> & erase, int N_row){
    auto p=row.begin();
    auto p_next_row=next_row.begin();
    auto last_p=row.end();
    auto last_p_next_row=next_row.end();

    if(row.get_nrow()==N_row-1 && next_row.get_nrow()==0){
        add.change_nrow(0);
        while(p!=last_p){
            if(p->car==1){
                while(p->col>p_next_row->col && p_next_row!=last_p_next_row){
                    p_next_row++;
                }
                if(p_next_row==last_p_next_row || p->col!=p_next_row->col){
                    POINT aux(p->col,1);
                    add.push_back(aux);
                    erase.push_back(p);
                }
            }
            p++;
        }
    }else{
        if(row.get_nrow()==N_row-1){add.change_nrow(0);}
        else {add.change_nrow(row.get_nrow()+1);}
        while(p!=last_p){
            if(p->car==1){
                POINT aux(p->col,1);
                add.push_back(aux);
                erase.push_back(p);
            }
            p++;
        }
    }
  }

void add_point(ROW & row, ROW & new_point){
    auto it=row.begin();
    auto last_point=new_point.end();
    for(auto point=new_point.begin();point!=last_point;point++){
        auto last=row.end();
        auto start=row.begin();
        it=lower_bound(start,last,*point,compare_POINT );
        row.insert(it,*point);
    }
}

void UpdateRedCol(ROW & row, int N_col){
    auto last_point=--row.end();
    auto point=row.begin();
    bool change_first=false;
    auto next_point=++row.begin();
    if(last_point->car==2){
        if(last_point->col==N_col-1){
            if(point->col!=0){
                change_first=true;
            }
        }else{
            last_point->col=last_point->col+1;
        }
    }
    for(point;point!=last_point;point++){
        if(point->car==2){
            if(next_point->col!=point->col+1){
                point->col=point->col+1;
            }
        }
        next_point++;
    }
    if(change_first){
        auto p=--row.end();
        auto first=row.begin();
        if(p==first){
            p->col=0;
        }else{
            auto p_prec=--(--row.end());
            for(p;p!=first;--p){
                *p=*p_prec;
                p_prec--;
            }
            first->col=0;
            first->car=2;
        }
    }
}


void MATRIX::update(){
    int N=data.size();

        if(move_blue){
            vector<ROW> add;
            ROW aux_first_row;
            vector<vector<POINT>::iterator>  erase;
            vector<ROW*> row_to_erase;
            UpdateLastBlueRow(data[N-1],data[0], aux_first_row,erase,N_row);
            if(aux_first_row.get_nrow()==0 && !aux_first_row.empty()){add.push_back(aux_first_row);}
            for(int i=0;i<N-1;i++){
                ROW aux_row;
                UpdateBlueRow(data[i], data[i+1], aux_row);
                if(!aux_row.empty()){add.push_back(aux_row);}
            }
            if(aux_first_row.get_nrow()!=0 && !aux_first_row.empty()){ add.push_back(aux_first_row);}

            int N_erase=erase.size()-1;
            for(int i=N_erase;i>=0;i--){
                data[N-1].erase(erase[i]);
            }
            //riad
            auto last=data.end();
            auto start=data.begin();
            auto last_row_to_add=add.end();
            auto r=data.begin();
            for(auto row_to_add=add.begin();row_to_add!=last_row_to_add;++row_to_add){
                r=lower_bound(start,last,*row_to_add,compare_ROW);
                if(row_to_add->get_nrow()==(r)->get_nrow()&&r!=last){
                    add_point(*r,*row_to_add);
                }else{
                    if(r!=last){
                        data.insert(--r,*row_to_add);
                    }else{
                        data.push_back(*row_to_add);
                    }
                }
            }

            auto first=data.begin();
            for(auto it=--data.end();it!=first;--it){
                if(it->empty()) data.erase(it);
            }
            if(first->empty()) data.erase(first);
            move_blue=false;
        }else{

            auto last=data.end();
            #pragma omp parallel for
            for(auto row=data.begin();row!=last;row++){
                UpdateRedCol(*row,N_col);
            }
            move_blue=true;
        }


}
