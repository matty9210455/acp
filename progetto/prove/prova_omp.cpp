#include<iostream>
#include<vector>
#include<omp.h>

using namespace std;
int main(){

#pragma parallel omp

int N=omp_get_num_threads();
int n=omp_get_thread_num();

cout<<N<<" "<<n<<endl;
return 0;
}
