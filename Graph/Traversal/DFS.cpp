#include <bits/stdc++.h>
using namespace std;

class solution {
    public:

    void DFS(int u, vector<bool>& visited, unordered_map<int, list<int>>& adjList, vector<int>& result){
        visited[u] = false;
        result.push_back(u);

        for(auto &v : adjList[u]){
            if(!visited[v]){
                DFS(v, adjList, visited, result)
            }
        }
    }
};

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

    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(i, visited, adjList, result);
        }
    }

    for(int i=0;i<V;i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}