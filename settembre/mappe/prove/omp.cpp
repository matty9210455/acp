#include<iostream>
#include<omp.h>

using namespace std;
int main(){
#pragma omp parallel
    {
        int n_th=omp_get_thread_num();
        int N_tot=omp_get_num_threads();
        for(size_t i=0;i<N_tot;i++){
            if(i==n_th){cout<<"threads "<<n_th<<" on "<<N_tot<<endl;}
#pragma omp barrier
        }
    }
}
