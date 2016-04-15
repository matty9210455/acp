#include"class.hpp"
#include"update.hpp"
#include<algorithm>

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
void search_and_erase(ROW & row, ROW & next_row, vector<POINT_CHANGE> & add, int n_row, int next_n_row){
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
    auto first_erase_point=erase.begin();
    for(auto erase_point=--erase.end();erase_point!=first_erase_point;--erase_point){
        row.erase(*erase_point);
    }
    row.erase(*first_erase_point);
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



void MATRIX::update(int iteraction){
    for(int i=0;i<iteraction;i++){
        if(move_blue){
            vector<POINT_CHANGE> add;
            vector<vector<POINT>::iterator> erase_last_row;
            //SEARCH AND ERASE
            auto row=--data.end();
            auto next_row=data.begin();
            search_and_erase(row->second,next_row->second,erase_last_row,add,row->first,next_row->first,N_row);
            auto last_row=data.end();
            row=next_row;
            for(++next_row;next_row!=last_row;++next_row){
                search_and_erase(row->second,next_row->second,add,row->first,next_row->first);
                ++row;
            }
            auto first_point_to_erase=erase_last_row.begin();
            --last_row;
            for(auto point_to_erase=--erase_last_row.end();point_to_erase!=first_point_to_erase;point_to_erase--){
                last_row->second.erase(*point_to_erase);
            }
            last_row->second.erase(*first_point_to_erase);
//ADDING

            move_blue=false;
        }

    }

}
