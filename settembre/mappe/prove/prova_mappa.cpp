#include<iostream>
#include<omp.h>
#include<map>

using namespace std;
int main(){

map<int,map<int,int> > a;
a[0][1]=1;
a[0][3]=1;
a[1][0]=2;
a[1][2]=2;
a[2][2]=1;
int N_row=3;
int N_col=5;
bool move_blue=true;

#pragma omp parallel
{
    int n_th=omp_get_thread_num();
    int N_tot=omp_get_num_threads();
    int aux=0;
    auto it_row=a.begin();
    for(size_t i=0+n_th;i<a.size();i=i+N_tot){
        while(aux<=i){
            it_row++;
            aux++;
        }
        cout<<"th "<<n_th<<" riga "<<it_row->first<<endl;
    }

}
}
