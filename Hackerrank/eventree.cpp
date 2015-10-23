/*
You are given a tree (a simple connected graph with no cycles). 
You have to remove as many edges from the tree as possible to 
obtain a forest with the condition that : 
Each connected component of the forest should contain an even number of vertices.

Sample input - 
10 9
2 1
3 1
4 3
5 2
6 1
7 2
8 6
9 8
10 8

Output - 2

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int dfsutil(int src, list<int> adj[], int *visited) {
    int totalsize = 0;
    if(adj[src].size()==0)
        visited[src] = 1;
    else 
        if(visited[src]==0) {
            std::list<int>::iterator i;
            for(i=adj[src].begin();i!=adj[src].end();++i) {
                totalsize += dfsutil(*i, adj, visited);
            }    
        }
    visited[src] = totalsize + 1;
    return visited[src];
} 

void dfs(int n, int m, list<int> adj[]) {
    int visited[n];
    int i;
    for(i =0; i<n;i++) {
        visited[i] = 0;
    }
    int ans = 0;
    dfsutil(0,adj,visited);
    for(i=1;i<n;++i) {
        if(visited[i]%2==0)
            ans++;
    }
    cout<<ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    std::list<int> *adj = new list<int>[n];
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[b].push_back(a);
    }
    
    dfs(n,m,adj);
    return 0;
}
