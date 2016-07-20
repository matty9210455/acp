#include<classi.hpp>
#include<iostream>
#include<algorithm>

using namespace std;


bool ComparePoint(point const & p1, point const & p2){
    if(p1.row<p2.row){
        return true;
    }else{
        if(p1.col<p2.col){
            return true;
        }
    };
    return false;
};


void UpdateBlue(vector<point> & data, vector<vector<point>::iterator> & erase, vector<point> & add){
    auto N=data.size();
    auto it=data.begin();
    auto fine=data.end();
    for(auto i=0;i<N;i++){
        if(data[i].car==1){
            point p=data[i];
            point aux(1,p.row+1,p.col);
            it=lower_bound(it,fine,aux,ComparePoint);
            if(it->col!=p.col){
                add.push_back(aux);
                erase.push_back(it);
            }
        }
    }
}
int main(){
    point p(1,2,1);
    point p1(1,1,2);
    point p2(2,1,1);
    point p3(3,2,2);
    point p4(4,2,1);
    cout<<ComparePoint(p1,p2)<<endl;
    cout<<ComparePoint(p1,p3)<<endl;
    cout<<ComparePoint(p2,p1)<<endl;
    cout<<ComparePoint(p3,p1)<<endl;
    cout<<ComparePoint(p2,p3)<<endl;
    vector<point> a{p2,p1,p4,p3};
    auto it=lower_bound(a.begin(),a.end(),p,ComparePoint );
            cout<<it->row<<" "<<it->col<<" "<<it->car<<endl;
            cout<<ComparePoint(p1,p)<<" "<<ComparePoint(p3,p)<<" "<<ComparePoint(p4,p)<<endl;
}
