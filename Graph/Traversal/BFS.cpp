#include <bits/stdc++.h>
using namesapce std;

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    for(int i=0;i<E;i++){
        int u, v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    unordered_map<int, list<int>> adjList(V);
    for(int i=0;i<E;i++){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> result;
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(0);
    visited[0] = false;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        result.push_back(u);

        for(auto &v : adjList[u]){
            if(!visited[i]){
                q.push(v);
            }
        }
    }

    for(int i=0;i<V;i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}