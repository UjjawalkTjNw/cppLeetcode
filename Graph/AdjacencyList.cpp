#include <bits/stdc++.h>
using namespace std;

class graph {
    public:
        //Unordered map, list, direction(o for undirected and 1 for directed)
        unordered_map<int, list<int>> adj;
        
        //add edges
        void AddEdge(int u , int v , bool direction){
            adj[u].push_back(v);
            
            //check directed of undirected
            //if undirecetd u should also be pushed to v;
            if(direction == 0) //unidrected
            {
                adj[v].push_back(u);
                
            }
        }
        
        //print adjacency list
        void printAdjList(){
            for(auto i : adj){
                cout << i.first << "->" ;
                for(auto j : i.second){  //second one is list so iterate
                    cout << j << "," ;
                }
                cout << endl ;
            }
        }
    
};
int main(){
    
    int n ;
    cout << "Enter number of nodes" << endl;
    cin >> n;
    
    
    int m;
    cout << "Enter number of edges" << endl;
    cin >>m ;
    
    
    graph g;
    
    //create graph by calling AddEdge
    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v ;
        g.AddEdge(u,v,0);
        
    }
    
    g.printAdjList();
    return 0;
}