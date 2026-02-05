#include <bits/stdc++.h>
using namespace std;

class solution{
    public: 

    void dfs(int u, unrdered_map<int, list<int>> &adjList, vector<bool> &vis){
        vis[u] = true;

        for(int &v : adjList[u]){
            if(!vis[v]){
                dfs(v, adjList, vis);
            }
        }
    }
}

int main(){
    int V;
    cin >> V;

    vector<vector<int>> adjMatrix(V, vector<int>(V));
    for(int i=0;i<V;i++){
        for(int i=0;i<V;i++){
            cin >> adjMatrix[i][j];
        }
    }

    // convert adjMatrix to adjList;

    unordered_map<int, list<int>> adjList(V);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adjMatrix[i][j] == 1){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<bool> vis(V, false);

    int cnt = 0;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;   // count no of provinces
            dfs(i, adjList, vis);
        }
    }

    cout << cnt << endl;
}