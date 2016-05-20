#include"classi.hpp"
#include<vector>
using namespace std;

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
            POINT aux(p->col,1);
            add.push_back(aux);
            erase.push_back(p);
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
void MATRIX::update(int iteraction){
    for(int it=0;it<iteraction;it++){
        if(move_blue){

        }
    }
}
