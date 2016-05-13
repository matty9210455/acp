#include"class.hpp"
#include"update.hpp"
#include<algorithm>
#include<iostream>

using namespace std;

void ROW::add_element_front(int col, int car){
    POINT new_point(col,car);
    auto el=_row.begin();
    auto last_el=_row.cend();
    while(el!=last_el){
        if(el->col>col){//va al primo posto
            _row.insert(el,new_point);
            return;
        }
        ++el;
    }
    _row.push_back(new_point);
}

//righe centrali
bool search_and_erase(ROW & row, ROW & next_row, vector<POINT_CHANGE> & add, int n_row, int next_n_row){
    vector<vector<POINT>::iterator> erase;
    auto next_row_point=next_row.begin();
    auto const last_point=row.end();
    auto const last_next_row_point=next_row.end();
    POINT_CHANGE aux;
    if(n_row==next_n_row-1){
        for(auto point=row.begin();point!=last_point;point++){
            if(point->car==1){
                while(next_row_point!=last_next_row_point && next_row_point->col<point->col ){
                    next_row_point++;
                };
                if(next_row_point!=last_next_row_point && next_row_point->col!= point->col ){
                    erase.push_back(point);
                    aux.row=n_row+1;
                    aux.col=point->col;
                    add.push_back(aux);
                }
            }
        }
    }else{
        for(auto point=row.begin();point!=last_point;point++){
            if(point->car==1){
                erase.push_back(point);
                aux.row=n_row+1;
                aux.col=point->col;
                add.push_back(aux);
            }
        }
    }
    if(erase.size()!=0){
        auto first_erase_point=erase.begin();
        for(auto erase_point=--erase.end();erase_point!=first_erase_point;--erase_point){
            row.erase((*erase_point));
        }
        row.erase(*first_erase_point);
    }
    if(row.size()==0) return true;
    return false;
}

//ultima riga
void search_and_erase(ROW & row, ROW & next_row, vector<vector<POINT>::iterator> & erase, vector<POINT_CHANGE> & add,int n_row,int next_n_row,int N_row){
    POINT_CHANGE aux;
    if(n_row==N_row-1 && next_n_row==0){
        auto next_row_point=next_row.begin();
        auto const last_point=row.end();
        auto const last_next_row_point=next_row.end();
        for(auto point=row.begin();point!=last_point;point++){
            if(point->car==1){
                while(next_row_point!=last_next_row_point && next_row_point->col<point->col ){
                    next_row_point++;
                };
                if(next_row_point!=last_next_row_point && next_row_point->col != point->col ){
                    erase.push_back(point);
                    aux.row=0;
                    aux.col=point->col;
                    add.push_back(aux);
                }
            }
        }
    }else{
       auto last_point=row.end();
       int _row=0;
       if(n_row!=N_row-1) _row=n_row+1;
       for(auto point=row.begin();point!=last_point;point++){
           if(point->car==1){
               erase.push_back(point);
               aux.row=_row+1;
               aux.col=point->col;
           }
       }
   }
}


void update_red(ROW & row, int N_col){
    ROW_iterator next_point=row.begin();
    ROW_iterator point=--row.end();
    ROW_iterator last_check=point;
    bool change_last=false;
    if(point->col!=N_col-1 && next_point->col!=0){
        change_last=true;
    }
    next_point++;
    for(point=row.begin(); point!=last_check;++point){
        if(point->car==2 && point->col!=next_point->col-1){
            point->up_red(N_col);
        }
        next_point++;
    }
    if(change_last) ;
}

void MATRIX::update(int iteraction){
    for(int i=0;i<iteraction;i++){
        if(move_blue){
            vector<POINT_CHANGE> add;
            vector<vector<POINT>::iterator> erase_last_row;
            vector<map<int,ROW>::iterator> row_to_erase;
            //SEARCH AND ERASE
            auto row=--data.end();
            auto next_row=data.begin();
            //ultima riga
            search_and_erase(row->second,next_row->second,erase_last_row,add,row->first,next_row->first,N_row);
            auto last_row=data.end();
            //righe centrali
            row=next_row;
            for(++next_row;next_row!=last_row;++next_row){
                if(search_and_erase(row->second,next_row->second,add,row->first,next_row->first)){
                    row_to_erase.push_back(row);
                }
                ++row;
            }
            //elimino punti ultima riga
            auto first_point_to_erase=erase_last_row.begin();
            --last_row;
            for(auto point_to_erase=--erase_last_row.end();point_to_erase!=first_point_to_erase;point_to_erase--){
                last_row->second.erase(*point_to_erase);
            }
            last_row->second.erase(*first_point_to_erase);
            if(last_row->second.size()==0){row_to_erase.push_back(last_row);}
            //elimino righe vuote

           if(row_to_erase.size()!=0){
                auto canc_first_row=row_to_erase.begin();
                for(auto canc_row=--row_to_erase.end(); canc_row=!canc_first_row; --canc_row){
                 data.erase(canc_row);
                }
                data.erase(canc_first_row);
            }
//ADDING

            move_blue=false;
        }else{
            auto last_row=data.end();
            int i=0;
            for(auto row=data.begin();row!=last_row;++row){
                update_red(row->second,N_col);
            }
            move_blue=true;
        }

    }

}
