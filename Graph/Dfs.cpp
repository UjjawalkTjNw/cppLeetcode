#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int>adj[], int s , int v){
    vector<bool>visited(v, false);
    //iterate over visited vector
    for(int i = 0 ; i<v ; i++){
        if(visited[i] == false)
           //recursive call its friend
           DFSRecursive(adj, i, visited);
    }

}

void DFSRecursive(vector<int>adj[], int s , vector<bool>visited){
    visited[s] = true;
    cout << s << endl;
    //now recursive check for its friends
    for(auto u : adj[s]){
        if(visited[u] == false)
           DFSRecursive(adj, u, visited);
    }
}