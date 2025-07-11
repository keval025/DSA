#include <bits/stdc++.h>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

void topoSort(int node, vector<int, bool> &visited, stack<int> &s, vector<int, list<int>> &adjList){
    visited[node] = 1;
    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            topoSort(neightbour, visited, s, adjList);
        }
    }
    s.push(node);
}

vector<int> topological(vector<vector<int>> &edges, int v, int e){
    //create adjList
    vector<int, list<int>> adjList;
    for(int i=0;i<e;++i){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i=0;i<v;++i){
        if(!visited[i]){
            topoSort(i, visited, s, adjList);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.front());
        s.pop();
    }
    return ans;
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<vctor<int>> edges;
    cin >> edges;

    return topological(edges, v, e);
}