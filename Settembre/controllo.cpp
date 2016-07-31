#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;


int main(int argc, char *argv[]){
    string prof=argv[1];
    string mie=argv[2];
    ifstream f1(prof);
    ifstream f2(mie);
    string s1;
    string s2;
    vector<vector<int>> A1;
    vector<vector<int>> A2;

    int i=0;
    int j=0;

    while(getline(f1,s1)){
        vector<int> aux;
        j=0;
        for(auto it=s1.begin();it<s1.end();it++){
            aux.push_back(atoi(&(*it)));

            if(i==9 && j==0)
            {cout<<"primo punto prima mat "<<i<<" "<<j<<atoi(&(*it));}
                        j++;
        }
        A1.push_back(aux);
        i++;
    }
    f1.close();
    i=0;
    j=0;
    while(getline(f2,s2)){
        j=0;
        vector<int> aux;
        for(auto it=s2.begin();it<s2.end();it++){
            aux.push_back(atoi(&(*it)));

            if(i==9 && j==0)
            {cout<<"primo punto prima mat "<<i<<" "<<j<<atoi(&(*it));}
                        j++;
        }
        A2.push_back(aux);
        i++;
    }
    f2.close();
    bool nessuno=true;
    cout<<"prima matrice "<<A1.size()<<" "<<A1[0].size()<<endl;
    cout<<"seconda matrice "<<A2.size()<<" "<<A2[0].size()<<endl;
    for(int i=0;i<A1.size();i++){
        for(int j=0;j<A1[i].size();j++){
            if(A1[i][j]!=A2[i][j]){
                nessuno=false;
                cout<<i<<" "<<j<<" prima mat "<<A1[i][j]<<" seconda mat "<<A2[i][j]<<endl;
            }
        }
    }
    if(nessuno){cout<<"fa paura"<<endl;}
}
