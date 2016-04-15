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

void find_point_to_update_blue(ROW & row, ROW & next_row, vector<vector<POINT>::iterator> & erase, vector<POINT_CHANGE> & add, int n_row, int N_row){

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
                POINT_CHANGE aux;
                if(n_row==N_row-1){
                    aux.row=0;
                    aux.col=point->col;
                    aux.car=1;
                }else{
                    aux.row=n_row+1;
                    aux.col=point->col;
                    aux.car=1;
                }
                add.push_back(aux);
            }
        }
    }

}
void MATRIX::update(int iteraction){
    for(int i=0;i<iteraction;i++){
        if(move_blue){
            vector<POINT_CHANGE> add;
            vector<vector<POINT>::iterator> erase;
            auto row=--data.end();
            auto next_row=data.begin();
                    //ULTIMA RIGA
            if(row->first==N_row-1){
                if(next_row->first==0){
                    find_point_to_update_blue(row->second, next_row->second,erase,add,N_row-1,N_row);
                }else{
                    auto const last_point=row->second.end();
                    POINT_CHANGE aux;
                    for(auto point=row->second.begin();point!=last_point;point++){
                        if(point->car==1){
                            erase.push_back(point);
                            aux.col=point->col;
                            aux.row=0;
                            aux.car=1;
                            add.push_back(aux);
                        }
                    }
                }
                //ALTRE RIGHE
            }else{
                next_row++;
                row=data.begin();
                if(row->first==next_row->first-1){
                    find_point_to_update_blue(row->second, next_row->second,erase,add,row->first,N_row);
                }
            }
        }
    }
}
