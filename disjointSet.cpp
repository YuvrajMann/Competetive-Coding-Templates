#include <bits/stdc++.h>
using namespace std;

vector<int> parents(10000);
vector<int> ranks(10000);

void makeset(){
    for(int i=0;i<10000;++i){
        parents[i]=i;
        ranks[i]=0;
    }
}

int findPar(int node){
    if(node==parents[node]){
        return node;
    }
    return parents[node]=findPar(parents[node]);
}

void union_conn(int u,int v){
    u=findPar(u);
    v=findPar(v);

    if(ranks[u]<ranks[v]){
        parents[u]=v;
    }
    else if(ranks[v]<ranks[u]){
        parents[v]=u;
    }
    else{
        parents[v]=u;
        ranks[u]++;
    }
}

int main(){
    makeset();

    union_conn(1,2);
    union_conn(2,3);
    union_conn(4,5);
    union_conn(6,7);
    union_conn(5,6);
    union_conn(3,7);

    if(findPar(2)!=findPar(6)){
        cout<<"Different Component"<<endl;
    }
    else{
        cout<<"Same Component"<<endl;
    }
    return 0;
}