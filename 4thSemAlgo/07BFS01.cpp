/*
7)a. Print all the nodes reachable from a given starting node in a digraph using BFS 
method. 
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to perform BFS
void bfs(int V,vector<int>& ans,vector<vector<int>>& adj);

int main(){
    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<int> ans;
    //Retrieving total number of vertices
    int V=adj.size();
    bfs(V,ans,adj);
    //Print reachable nodes
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}

void bfs(int V,vector<int>& ans,vector<vector<int>>& adj){
    //to keep track of visited nodes
    vector<bool> isVisited(V,false);
    queue<int> q;
    //Starting node for BFS traversal
    int start=0;
    isVisited[start]=true;
    q.push(start);
    while (!q.empty()){
        //get the front element
        int node=q.front();
        //remove the front element
        q.pop();
        ans.push_back(node);
        for(int item:adj[node]){
            if(!isVisited[item]){
                isVisited[item]=true;
                q.push(item);
            }    
        }
    }
}

/*
-----------------------------------Algorithm-------------------------------
1)Start by putting any one of the graph's vertices at the back of a queue.
2)Take the front item of the queue and add it to the visited list.
3)Create a list of that vertex's adjacent nodes. Add the ones which aren't 
    in the visited list to the back of the queue.
4)Keep repeating steps 2 and 3 until the queue is empty.

----------Complexity-------------------------
Time Complexity: O(V + E)
Auxiliary Space: O(V)
*/