/*
This func is for connected graph
Requirements: adjacency list, No of nodes(v), source node(s)
*/
#include <bits/stdc++.h>
using namespace std; 
void BFS(vector<int> adj[], int v, int s){
    vector<bool>visited;
    queue<int>q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " " ;

        //Now go to adjacency list
        for(auto v: adj[u]){
            if(visited[v] == false){
                visited[v] == true;
                 q.push(v);
            }
           

        }
    }

}