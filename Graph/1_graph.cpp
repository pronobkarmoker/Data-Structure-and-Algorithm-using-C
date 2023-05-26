#include<iostream>
#include <vector>
using namespace std;

int main(){

    // MATRIX...........
    int n , m;
    cin>> n >> m;
    int adjMAt[n+1][m+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMAt[u][v]= 1;
        adjMAt[v][u] = 1;

    }

    // weighted graph.........
    int n , m, weight;
    cin>> n >> m;
    int adjMAt[n+1][m+1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMAt[u][v]= weight;
        adjMAt[v][u] = weight;

    }

    // LIST..........
    // undirected
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    // if directed
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        // a ----->b
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int, int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int a, b, weight;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    

    return 0;
    
}
