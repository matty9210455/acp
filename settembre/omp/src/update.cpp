#include<classi.hpp>
#include<vector>
#include<omp.h>

using namespace std;

void matrix::update(int N_iter){
    for(size_t iter=0;iter<N_iter;iter++){
        vector<point_to_erase> erasePrincipal;
        vector<point> addPrincipal;
        auto last_row=data.end();
        if(move_blue){
#pragma omp parallel
            {
            vector<point_to_erase> erase;
            vector<point> add;
            int n_th=omp_get_thread_num();
            int N_tot=omp_get_num_threads();
            auto it_row=data.begin();
            int aux_par=0;
            auto N_row=data.size();
            for(size_t i=0+n_th;i<N_row;i=i+N_tot){
                while(aux_par<i){
                    it_row++;
                    aux_par++;
                }
                auto next_row=data.find(it_row->first+1);
                if(it_row->first==N_row-1) {next_row=data.find(0);}
                if(next_row!=last_row){
                    auto last_point=it_row->second.end();
                    auto last_nextRow_point=next_row->second.end();
                    for(auto it=it_row->second.begin();it!=last_point;it++){
                        if(it->second==1){
                            auto aux=next_row->second.find(it->first);
                            if(aux==last_nextRow_point){
                                point aux_add(it_row->first+1,it->first,1);
                                if(aux_add.row==N_row){aux_add.row=0;}
                                add.push_back(aux_add);
                                point_to_erase aux_er(it_row,it);
                                erase.push_back(aux_er);
                            }
                        }
                    }
                }else{
                    auto last_point=it_row->second.end();
                    for(auto it=it_row->second.begin();it!=last_point;it++){
                        if(it->second==1){
                                point aux_add(it_row->first+1,it->first,1);
                                if(aux_add.row==N_row){aux_add.row=0;}
                                add.push_back(aux_add);
                                point_to_erase aux_er(it_row,it);
                                erase.push_back(aux_er);
                        }
                    }
                }
            }
#pragma omp barrier
            for(int i_th=0;i_th<N_tot;i_th++){
                if(n_th==i_th){
                    erasePrincipal.insert(erasePrincipal.end(),erase.begin(),erase.end());
                    addPrincipal.insert(addPrincipal.end(),add.begin(),add.end());

                }
#pragma omp barrier
            }
            }
            move_blue=false;
        }else{
#pragma omp parallel
            {
                vector<point_to_erase> erase;
                vector<point> add;
                int n_th=omp_get_thread_num();
                int N_tot=omp_get_num_threads();
                auto it_row=data.begin();
                int aux_par=0;
                auto N_row=data.size();
                for(size_t i=0+n_th;i<N_row;i=i+N_tot){
                    while(aux_par<i){
                        it_row++;
                        aux_par++;
                    }
                auto last_point=it_row->second.end();
                for(auto it=it_row->second.begin();it!=last_point;it++){
                    if(it->second==2){
                        auto aux=it_row->second.find(it->first+1);
                        if(it->first==N_col-1){aux=it_row->second.find(0);}
                        if(aux==last_point){
                            point aux_add(it_row->first,it->first+1,2);
                            if(aux_add.col==N_col){aux_add.col=0;}
                            add.push_back(aux_add);
                            point_to_erase aux_er(it_row,it);
                            erase.push_back(aux_er);
                        }
                    }
                }
            }
#pragma omp barrier
                for(int i_th=0;i_th<N_tot;i_th++){
                    if(n_th==i_th){
                        erasePrincipal.insert(erasePrincipal.end(),erase.begin(),erase.end());
                        addPrincipal.insert(addPrincipal.end(),add.begin(),add.end());

                    }
#pragma omp barrier
                }
            }
            move_blue=true;
        }

        //erase

        auto N_change=erasePrincipal.size();
        for(size_t i=0;i<N_change;i++){
            erasePrincipal[i].row->second.erase(erasePrincipal[i].col);
        }

        //add

        for(size_t i_add=0;i_add<N_change;i_add++){
            data[addPrincipal[i_add].row][addPrincipal[i_add].col]=addPrincipal[i_add].car;
        }
        auto it_row=data.begin();
        while (it_row!=last_row) {
            if(it_row->second.size ()==0){
                auto aux=it_row;
                it_row++;
                data.erase(aux);
            }else{
                it_row++;
            }
        }
    }
}
