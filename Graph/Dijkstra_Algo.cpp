#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src){
    unordered_map<int, list<pair<int,int>>> adjList;
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;
    dist[src] = 0;
    st.insert(make_pair(0, src));
    while(!st.empty()){
        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour : adjList[topNode]){
            if(nodeDist + neighbour < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if(record != st.end()){
                    st.erase(record);
                }
                dist[neighbour.first] = nodeDist + neighbour.second;

                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main(){
    int vertices, edges, src;
    cin >> vertices >> edges >> src;

    vector<vector<int>> vec;
    for(int i=0;i<edges;i++){
        cin >> vec[i];
    }

    return dijkstra(vec, vertices, edges, src);
}