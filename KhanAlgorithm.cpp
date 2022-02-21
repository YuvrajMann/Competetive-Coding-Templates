#include <bits/stdc++.h>
using namespace std;

void khanAlgo(int V, vector<vector<int>> &adj){
    vector<int> in_degree(V, 0);
    
    for (int u = 0; u < V; u++) {
        for (auto itr = adj[u].begin();itr != adj[u].end(); itr++){
            in_degree[*itr]++;
        }      
    }

    queue<int> q;
    for (int i = 0; i < V; i++){
        if (in_degree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0; 
    vector<int> top_order;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
 
        for (auto itr = adj[u].begin();itr != adj[u].end(); itr++){
            if (--in_degree[*itr] == 0){
                q.push(*itr);
            }
        }
        cnt++;
    }
 
    if (cnt != V) {
        cout << "There exists a cycle in the graph\n";
        return;
    }
    cout<<top_order.size()<<endl;
    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";
    cout << endl;
}
int main(){
    int n=6;
    vector<vector<int>> adj(n);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1); 
   
    khanAlgo(n,adj);
}