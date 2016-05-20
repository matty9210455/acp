#include"classi.hpp"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare_POINT(POINT const & p1, POINT const & p2){ return p1.col<p2.col; }

bool compare_ROW(ROW const & r1, ROW const & r2){return r1.get_nrow() < r2.get_nrow();}

void UpdateBlueRow(ROW & row, ROW & next_row, ROW & add){

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
            POINT aux(p->col,1);
            add.push_back(aux);
            erase.push_back(p);
            p++;
        }
    }

    if(erase.size()>0){
        add.change_nrow(row.get_nrow()+1);
    }

  }

void add_point(ROW & row, ROW & new_point){
    auto last=row.end();
    auto it=row.begin();
    auto last_point=new_point.end();
    for(auto point=new_point.begin();point!=last_point;point++){
        it=lower_bound(it,last,*point,compare_POINT );
        row.insert(it,*point);
    }
}

void MATRIX::update(int iteraction){
    for(int it=0;it<iteraction;it++){
        int N=data.size();
        if(move_blue){
            vector<ROW> add;
            ROW aux_first_row;
            vector<vector<POINT>::iterator>  erase;
            UpdateLastBlueRow(data[N-1],data[0], aux_first_row,erase,N_row);
            if(data[N-1].get_nrow()==N_row-1 && aux_first_row.size()!=0) add.push_back(aux_first_row);
            for(int i=1;i<N;i++){
                ROW aux_row;
                UpdateBlueRow(data[i-1], data[i], aux_row);
                if(aux_row.size()!=0) add.push_back(aux_row);
            }
            int N_erase=erase.size()-1;
            for(int i=N_erase;i>=0;i--){
                data[N-1].erase(erase[i]);
            }
            if(data[N-1].get_nrow()!=N_row-1 && aux_first_row.size()!=0) add.push_back(aux_first_row);
            //riadd
            auto last=data.end();
            auto last_row_to_add=add.end();
            auto r=data.begin();
            cout<<"ok "<<add.size()<<endl;

            for(auto row_to_add=add.begin();row_to_add!=last_row_to_add;++row_to_add){
                                    cout<<"entrato12"<<endl;
                r=lower_bound(r,last,*row_to_add,compare_ROW);
                if(r!=data.begin() && row_to_add->get_nrow()==(--r)->get_nrow()){
                    cout<<"entrato"<<endl;
                    add_point(*r,*row_to_add);
                }else{
                    data.insert(r,*row_to_add);
                }
            }
        }
    }
}
