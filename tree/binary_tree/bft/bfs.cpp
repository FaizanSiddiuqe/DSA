#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to add an edge to the graph (undirected graph)
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Remove this line for directed graph
}

// Function to perform BFS traversal from a given source node
void BFS(vector<int> adj[], int vertices, int start) {
    // Create a visited array to track visited nodes
    vector<bool> visited(vertices, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the start node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    // BFS loop
    cout << "BFS Traversal starting from node " << start << ": ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // Print the node

        // Explore all adjacent nodes of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor); // Enqueue the unvisited neighbor
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices = 5; // Number of vertices in the graph
    vector<int> adj[vertices]; // Adjacency list

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Perform BFS starting from node 0
    BFS(adj, vertices, 0);

    return 0;
}
