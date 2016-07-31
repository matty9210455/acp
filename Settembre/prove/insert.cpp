#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    vector<int>::iterator aux=v.begin();

    vector<int> to_add;
    to_add.push_back(3);
    to_add.push_back(5);
    to_add.push_back(7);
    to_add.push_back(9);
    int N=v.size();
    int j=0;
    for(int i=0;i<to_add.size();i++){
            bool inserito=true;
        while(j<N && inserito){
            if(to_add[i]<v[j]){
                v.insert(v.begin()+j,to_add[i]);
                j++;
                N++;
                inserito=false;
            }
            j++;
        }
        if(j==N && inserito){
            v.push_back(to_add[i]);
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}
