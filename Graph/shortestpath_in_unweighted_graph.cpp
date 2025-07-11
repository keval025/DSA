#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> &edges, int n, int m, int s, int t){
    unordered_map<int, list<int>> adjList;

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.pusH(s);
    parent[s] = -1;
    visited[s] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adjList[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // prepare shortestPath
    vector<int> ans;
    int currNode = t;
    ans.push_back(currNode);
    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<pair<int, int>> edges;
    cin >> edges;

    return shortestPath(edges, n, m, s, t);
}