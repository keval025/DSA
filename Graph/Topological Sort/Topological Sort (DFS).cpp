#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    void DFS(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st){
        vis[u] = true;

        for(int &v : adj[u]){
            if(!vis[v]){
                DFS(v, adj, vis, st);
            }
        }

        st.push(u);
    }

    vector<int> topoSort(int V, vector<vector<int>> &adj){
        vector<bool> vis(V, false);
        stack<int> st;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                DFS(i, adj, vis, st);
            }
        }

        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
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