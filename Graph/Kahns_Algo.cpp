#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    //create adjList
    vector<list<int>> adjList(v); 
    for(int i=0;i<e;++i){
        int u = edges[i][0];
        int vv = edges[i][1];

        adjList[u].push_back(vv);
    }

    vector<int> inDegree(v);
    for(const auto &nbrs : adjList){
        for(int j : nbrs){
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
        for(int neighbour : adjList[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}

int main(){
    int v, e;
    if(!(cin >> v >> e)) return 0;
    vector<vector<int>> edges(e, vector<int>(2));
    for(int i=0;i<e;++i){
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> order = topologicalSort(edges, v, e);
    for(size_t i=0;i<order.size();++i){
        cout << order[i] << (i + 1 < order.size() ? ' ' : '\n');
    }
    return 0;
}