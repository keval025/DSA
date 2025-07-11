#include <bits/stdc++.h>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

vector<int> shortesPath(vector<pair <int>> &edges, int n, int src){
    unordered_map<int, list<pair<int, int>>> adjList;

    for(int i=0;i<n;++i){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);      
    }

    unordered_map<int, bool> visited;
    stack<int> st;

    for(int i=0;i<n;++i){
        if(!visited[i]){
            dfa(i, visited, st, adjList);
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<pair<int, int>>> &adjList){
        visited[node] = true;

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first, visited, st, adjList);
            }
        }
        st.push(node);
    }

    vector<int> dist(n);
    for(int i=0;i<n;++i){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();

        if(dist[top] != INT_MAX){
            for(auto i : adjList[top]){
                if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n, src;
    cin >> n, src;
    
    vector<pair<int>> edges;
    cin >> edges;

    return shortestPath(edges, n, src);
}