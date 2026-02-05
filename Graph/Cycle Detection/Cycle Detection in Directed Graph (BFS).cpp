// Same As Kahns Algo  --------> Kahns Algo is Appliable in DAG (Directec Acyclic Graph)  So, When Kahns is not Applicable then Cycle is Detected in Graph

#include <bits/stdc++.h>
using namespace std;

class solution {
    public:

    string cycleDetection(int V, unordered_map<int, list<int>> &adjList, vector<bool> &visited){
        queue<int> q;
        vector<int> inDegree(V, 0);

        for(int i=0;i<V;i++){
            for(int &v : adjList[u]){
                inDegree[v]++;
            }
        }

        for(int i=0;i<V;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;

        while(!q.empty()){
            int u = q.front();
            cnt++;
            q.pop();
            for(int &v : adjList[u]){
                inDegree[v]--;

                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(cnt == V) {
            return cycleIsNotPresent;
        }
        return cycleIsPresnt;
    }
}

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
        adjList[edges[i][0]].push_back(edges[i][1]);
    }

    cout << cycleDetection(V, adjList);
}