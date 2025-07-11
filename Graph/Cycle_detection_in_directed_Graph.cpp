#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

bool isCyclic(int node, unordered_map<int, bool>& visited,unordered_map<int, bool>> &dfsVisited, unordered_map<int, list<int>>& adjList){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclic(neighbour, visited, dfsVisite, adjList);
            if(cycleDetected)
             return true;
        }else if(dfsVisite[neighbour]){
            return true;
        }
    }
    dfsVisite[node] = false;
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m){
    //create adgList
    unordered_map<int, list<int>> adjList;
    for(int i=0;i<m;++i){
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        //adjList[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for(int i=0;i<n;++i){
        if(!visited[i]){
            bool ans = isCyclic(i, visited,dfsVisite, adjList);
            if(ans == 1){
                return "YES";
            }
        }
    }
    return "NO";
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    cin >> edges;

    return cycleDetection(edges, n, m);
}