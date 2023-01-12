// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
/*#include<bits/stdc++.h>
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    vector<list<int>> adj;  
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints BFS traversal from a given source s
    void BFS(int s); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent: adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,4);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
*/



#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T> > l;

public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src){
        map<T, int> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(int nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfs_help(T src, map<T,bool> &visited){
        cout<<src<<" ";
        visited[src] = true;
        for(T nbr:l[src]){
            if(!visited[nbr])
                dfs_help(nbr, visited);
        }
    }

    void dfs(T src){
        map<T, bool> visited;

        for(auto p:l){
            T node = p.first;
            visited[node] = false;
        }

        dfs_help(src, visited); 
    }
};


int main(){
    Graph<int> g;
    g.addEdge(0,2);
    g.addEdge(0,1);
    g.addEdge(2,0);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.bfs(0);
    cout<<endl;
    g.dfs(0);
    return 0;
}
