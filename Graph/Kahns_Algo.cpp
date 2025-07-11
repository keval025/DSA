#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    //create adjList
    vector<int, list<int>> adjList; 
    for(int i=0;i<e;++i){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    vector<int> inDegree(v);
    for(auto i : adjList){
        for(auto j : i.second){
            inDegree[j]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;++i){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour : adjList[front]){
            indegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                p.push(neighbour);
            }
        }
    }
    return ans;
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    cin >> edges;

    return topologicalSort(edges, v, e);
}