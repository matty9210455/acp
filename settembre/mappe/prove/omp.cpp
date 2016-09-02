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
auto it_row=a.begin();

for(int aux=0;aux<n_th;aux++){it_row++;}//prima riga

for(int ind_row=0+n_th;ind_row<a.size();ind_row=ind_row+N_tot){
    for(int th=0;th<N_tot;th++){
        if(n_th==th){
            cout<<"threads "<<n_th<<" riga "<<it_row->first;
            for(auto it=it_row->second.begin();it!=it_row->second.end();it++){
                cout<<" colonna "<<it->first<<" macchina "<<it->second;
            }
            cout<<endl;
        }
        for(int aux=0;aux<N_tot;aux++){it_row++;}
#pragma omp barrier
    }
}

}
}
