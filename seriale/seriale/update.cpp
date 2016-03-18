#include "classi.hpp"
#include<vector>

using namespace std;

void sparse_matrix::update(int N_iteration){
    const MATRIX::iterator end_matrix=A.end();
    for(int iter=0; iter<N_iteration; iter++){
        vector<ROW::iterator> move;
        vector<int> row_move;
        int row(0);
        MATRIX::iterator it_matrix=A.begin();
        if(move_blue){
            MATRIX::iterator next_row=A.begin();
            next_row++;
            //controllo quali blu spostare
            for(it_matrix;it_matrix!=end_matrix;it_matrix++){

                const ROW::iterator end_row=it_matrix->second.end();
                const ROW::iterator end_next_row=next_row->second.end();
                ROW::iterator el=it_matrix->second.begin();
                ROW::iterator el_next_row=next_row->second.begin();
                for(el;el!=end_row;el++){
                    while(el_next_row!= end_next_row && el_next_row->first < el->first){
                        el_next_row++;
                    }
                    if(el->second==1){
                        if(el_next_row!= end_next_row &&
                           el_next_row->first != el->first ){
                                  move.push_back(el);
                                  row_move.push_back(row);
                        }
                        if(el_next_row==end_next_row){
                            move.push_back(el);
                            row_move.push_back(row);
                        }
                    }
                }
                row++;
                next_row++;
            }
            //update
             vector<ROW::iterator>::iterator move_el=move.begin();
             const vector<ROW::iterator>::iterator move_el_end=move.end();
             int pos_row(0);
             for(move_el;move_el!=move_el_end;move_el++){
                while()
             }


            move_blue=false; // cambio macchine da spostare
        }else{
            //controllo quali rosse sposto
            for(it_matrix;it_matrix!=end_matrix;it_matrix++){
                const ROW::iterator end_row=it_matrix->second.end();
                ROW::iterator el=it_matrix->second.begin();
                ROW::iterator el_next=el;
                el_next++;
                for(el;el!=end_row;el++){
                    if(el->second==2){
                        if(el_next!=end_row &&
                           el->first < el_next->first-1 &&
                           el->first != N_col-1){
                            move.push_back(el);
                            row_move.push_back(row);
                        }
                        if(el_next==end_row && el->first!=N_col-1){
                            move.push_back(el);
                            row_move.push_back(row);
                        }
                        if(el->first==N_col-1 && it_matrix->second.begin()->first!=0){
                            move.push_back(el);
                            row_move.push_back(row);
                        }
                    }
                    el_next++;
                }
                row++;
            }
            //update

            move_blue=true; // cambio macchine da spostare
        }
    }
}
