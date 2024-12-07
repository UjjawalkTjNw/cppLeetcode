/*
This code will handle the case of a disconnected graph
suppose there are two disconncted graph : Graph 1 size 3, graph 2 size 4
*/

//defination of BFS called inside BFSdis

void BFS(vector<int>adj[] , int s , vector<bool>& visited)
{
    queue<int>q;
    visited[s]= true;
    q.push(s);

    //rest of code is same as Normal graph bfs
}

void BFSdis(vector<int>adj, int v){ //v is number of nodes
     vector<bool> visited(v+1,false); //This visited array will contain total elemets space 7(3+4)
     for(int i = 0 ; i < v ; i++){
        if(visited[i] == false){
            BFS(adj,i , visited);

        }
     }


}