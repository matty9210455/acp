#include"class.hpp"

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

void MATRIX::update(int iteraction){
    for (int i=0; i<=iteraction;i++){
        if(move_blue){
           vector<POINT> change;
        //CONTROLLO
           //ultima riga

           auto row=--data.end()
           auto next_row=data.begin();

           auto next_it=next_row.begin();
           auto last_next_it=next_row.cend();
           for(auto it=row.begin();it!=row.end();it++){
             while(next_it->col<it->col && next_it!= last_next_it) next_it++;

           }
           MATRIX_iterator const last_row=--data.end();
           for(auto row=data.begin();row!=last_row;++row){

           }
        }else{

        }
    }
}
