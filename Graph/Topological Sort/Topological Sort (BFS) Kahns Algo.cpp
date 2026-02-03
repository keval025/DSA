#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    vector<int> topoSort(int V, vector<vector<int>> &adj){
        vector<int> inDeg(V, 0);

        for(int i=0;i<V;i++){
            for(int &v : adj[i]){
                inDeg[v]++;
            }
        }

        queue<int> q;
        vector<int> result;

        for(int i=0;i<V;i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front;
            result.push_back(u);
            q.pop();
            for(int &v : adj[u]){
                inDeg[v]--;

                if(inDeg[v] == 0){
                    q.push(v);
                }
            }
        }

        return result;
    }
}

int main(){
    int V, E;
    cin >> V, E;

    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    cout << topoSort(V, adj) << endl;

    return 0;
}