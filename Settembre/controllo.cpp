#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;


int main(){
    string prof="100_p.csv";
    string mie="100.csv";
    ifstream f1(prof);
    ifstream f2(mie);
    string s1;
    string s2;
    vector<vector<int>> A1;
    vector<vector<int>> A2;

    while(getline(f1,s1)){
        vector<int> aux;
        for(auto it=s1.begin();it<s1.end();it++){
            aux.push_back(atoi(&(*it)));
        }
        A1.push_back(aux);
    }
    while(getline(f2,s2)){
        vector<int> aux;
        for(auto it=s2.begin();it<s2.end();it++){
            aux.push_back(atoi(&(*it)));
        }
        A2.push_back(aux);
    }
    bool nessuno=true;
    cout<<"prima matrice "<<A1.size()<<" "<<A1[0].size()<<endl;
    cout<<"seconda matrice "<<A2.size()<<" "<<A2[0].size()<<endl;
    for(auto i=0;i<A1.size();i++){
        for(auto j=0;j<A1[i].size();j++){
            if(A1[i][j]-A2[i][j]){
                nessuno=false;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    if(nessuno){cout<<"fa paura"<<endl;}
}
