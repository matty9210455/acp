#include<iostream>
#include<map>
#include<vector>


using namespace std;

struct point{
    int row;
    int col;
    int car;
public:
    point(int _row, int _col, int _car) : car(_car), row(_row), col(_col) {};
};

typedef typename map<int,map<int,int> >::iterator iterator_row;
typedef typename map<int,int>::iterator iterator_point;

struct point_to_erase{
    /*iterator_row row;
    iterator_point col;*/
    int row;
    int col;
public:
    point_to_erase( int _row, int _col ) :  row(_row), col(_col) {};
};

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
auto fine_righe=a.end();
for(size_t i=0;i<N_row;i++){
    auto aux_row=a.find(i);
    if(aux_row!=fine_righe){
        auto fine_col=a[i].end();
        for(size_t j=0;j<N_col-1;j++){
            auto aux_col=a[i].find(j);
            if(aux_col!=fine_col){
                cout<<aux_col->second<<",";
            }else{
            cout<<0<<",";
            }
        }
        auto aux_col=a[i].find(N_col-1);
        if(aux_col!=fine_col){
            cout<<aux_col->second<<endl;
        }else{
        cout<<0<<endl;
        }
    }else{
        for(size_t j=0;j<N_col-1;j++){
            cout<<0<<",";
        }
        cout<<0<<endl;
    }
}
cout<<endl;

/*
 for(auto it_row=a.begin();it_row!=a.end();it_row++){
    cout<<"elementi per riga "<<(it_row)->second.size()<<endl;
    for(auto it=it_row->second.begin();it!=it_row->second.end();it++){
        cout<<"riga "<<it_row->first<<" colonna "<<it->first<<" macchina "<<it->second<<endl;
    }
}
cout<<endl;
*/

for(int iter=0;iter<5;iter++){
vector<point_to_erase> erase;
vector<point> add;
if(move_blue){
#pragma omp parallel
{
int n_th=omp_get_thread_num();
int N_tot=omp_get_num_threads();
for(auto it_row=a.begin()+n_th;it_row<a.end();it_row=it_row+N_tot){
    for(auto it=it_row->second.begin();it!=it_row->second.end();it++){
        if(it->second==1){
        if(it_row->first!=N_row-1){
            auto aux_row=a.find(it_row->first+1);
            if(aux_row!=a.end()){
                auto aux_col=a[it_row->first+1].find(it->first);
                if(aux_col==a[it_row->first+1].end()){
                    point aux_add(it_row->first+1,it->first,1);
                    add.push_back(aux_add);
                    point_to_erase aux_er(it_row->first,it->first);
                    erase.push_back(aux_er);
                }
            }else{
                point aux_add(it_row->first+1,it->first,1);
                add.push_back(aux_add);
                point_to_erase aux_er(it_row->first,it->first);
                erase.push_back(aux_er);
            }
        }else{
            auto aux_row=a.find(0);
            if(aux_row!=a.end()){
                auto aux_col=a[0].find(it->first);
                if(aux_col==a[0].end()){
                    point aux_add(0,it->first,1);
                    add.push_back(aux_add);
                    point_to_erase aux_er(it_row->first,it->first);
                    erase.push_back(aux_er);
                }
            }else{
                point aux_add(0,it->first,1);
                add.push_back(aux_add);
                point_to_erase aux_er(it_row->first,it->first);
                erase.push_back(aux_er);
            }
        }
        }
    }
}
}
}else{
    for(auto it_row=a.begin();it_row!=a.end();it_row++){
        for(auto it=it_row->second.begin();it!=it_row->second.end();it++){
            auto fine_col=it_row->second.end();
            if(it->second==2){
            if(it->first!=N_col-1){
                auto aux=it_row->second.find(it->first+1);
                if(aux==fine_col){
                    point aux_add(it_row->first,it->first+1,2);
                    add.push_back(aux_add);
                    point_to_erase aux_er(it_row->first,it->first);
                    erase.push_back(aux_er);
                }
            }else{
                auto aux=it_row->second.find(0);
                if(aux==fine_col){
                    point aux_add(it_row->first,0,2);
                    add.push_back(aux_add);
                    point_to_erase aux_er(it_row->first,it->first);
                    erase.push_back(aux_er);
                }
            }
            }
        }
    }
}

move_blue=!move_blue;
for(int i_er=erase.size()-1;i_er>=0;i_er--){
    a[erase[i_er].row].erase(erase[i_er].col);
    if(a[erase[i_er].row].size()==0){
        a.erase(erase[i_er].row);
    }
}

for(size_t i_add=0;i_add<add.size();i_add++){
    a[add[i_add].row][add[i_add].col]=add[i_add].car;
}



fine_righe=a.end();
for(size_t i=0;i<N_row;i++){
    auto aux_row=a.find(i);
    if(aux_row!=fine_righe){
        auto fine_col=a[i].end();
        for(size_t j=0;j<N_col-1;j++){
            auto aux_col=a[i].find(j);
            if(aux_col!=fine_col){
                cout<<aux_col->second<<",";
            }else{
            cout<<0<<",";
            }
        }
        auto aux_col=a[i].find(N_col-1);
        if(aux_col!=fine_col){
            cout<<aux_col->second<<endl;
        }else{
        cout<<0<<endl;
        }
    }else{
        for(size_t j=0;j<N_col-1;j++){
            cout<<0<<",";
        }
        cout<<0<<endl;
    }
}
cout<<endl;


}


return 0;
}
