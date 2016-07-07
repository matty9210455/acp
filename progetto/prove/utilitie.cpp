
struct point_to_add{
    int col;
    int row;
}


void UpdateLastBlueRow
int N=data.size();

    if(move_blue){
#pragma omp parallel{//inizio parallelo
    vector<point_to_add> p;
    vector<vector<POINT>::iterator>  erase;
    vector<ROW*> row_to_erase;
    int N_TOT=omp_get_num_threads();
    int n_th=omp_get_thread_num();
    int ultimo=0;
    int primo=0;
    if(n_th!=N_TOT-1){
        ultimo=(N/N_TOT)*(n_th+1)-1;
        primo=(n_th)*(N/N_TOT);
    }else {
        ultimo=N-1;
        primo=(n_th)*(N/N_TOT);
    }

   if(n_th=N_TOT-1) UpdateLastBlueRow(data[ultimo],data[0], p,erase);
#pragma omp barrier
   UpdateFirstBlueRow(data[primo],data[primo+1],p,erase)
    for(int index=primo+1;index<ultimo;index++){
       UpdateBlueRow(data[index],data[index+1],p)
   }
#pragma omp barrier
   //aggiunta punti
   for(i_th=0;i_th<N_TOT;i_th++){
       if(n_th==i_th){

       }
#pragma omp barrier
   }
#pragma omp barrier
}//fine parallelo
move_blue=false;
}







void UpdateLastBlueRow(ROW & row, ROW & next_row, vector<point_to_add> & p,erase);
