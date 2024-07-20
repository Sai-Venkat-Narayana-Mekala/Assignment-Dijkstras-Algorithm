#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define MAX_VERTICES 100 // Maximum number of vertices allowed in the graph

// Class representing a graph using an adjacency matrix
class NewImpGraph {
public:
    int adjMatrixNewImp[MAX_VERTICES][MAX_VERTICES]; // Matrix to store edge weights
    int numVerticesNewImp; // Number of vertices in the graph

    // Constructor to initialize the graph with a specified number of vertices
    NewImpGraph(int vertices) {
        numVerticesNewImp = vertices;
        // Initialize the adjacency matrix
        for (int i = 0; i < numVerticesNewImp; ++i) {
            for (int j = 0; j < numVerticesNewImp; ++j) {
                // Set weight to 0 for self-loops and to INT_MAX (infinity) for other edges
                adjMatrixNewImp[i][j] = (i == j) ? 0 : INT_MAX;
            }
        }
    }

    // Method to add an edge between two vertices with a specified weight
    void addEdgeNewImp(int u, int v, int weight) {
        adjMatrixNewImp[u][v] = weight;
        adjMatrixNewImp[v][u] = weight; // For undirected graphs, mirror the edge
    }
};

// Class implementing Dijkstra's algorithm for finding the shortest path
class NewImpDijkstra {
public:
    // Method to compute the shortest path from the start node to the end node
    void shortestPathNewImp(NewImpGraph& graph, int start, int end) {
        int distNewImp[MAX_VERTICES]; // Array to store shortest distances from the start node
        bool visitedNewImp[MAX_VERTICES]; // Array to track visited nodes
        int prevNewImp[MAX_VERTICES]; // Array to remember the previous node in the shortest path

        // Initialize distances, visited status, and previous nodes
        for (int i = 0; i < graph.numVerticesNewImp; ++i) {
            distNewImp[i] = INT_MAX; // Set all distances to infinity initially
            visitedNewImp[i] = false; // All nodes are initially unvisited
            prevNewImp[i] = -1; // No previous node initially
        }
        distNewImp[start] = 0; // Distance from the start node to itself is zero

        // Main loop to find the shortest path
        for (int i = 0; i < graph.numVerticesNewImp; ++i) {
            // Find the unvisited node with the smallest distance
            int minDistNewImp = INT_MAX, minIndexNewImp = -1;
            for (int j = 0; j < graph.numVerticesNewImp; ++j) {
                if (!visitedNewImp[j] && distNewImp[j] < minDistNewImp) {
                    minDistNewImp = distNewImp[j];
                    minIndexNewImp = j;
                }
            }

            // Exit if no more reachable nodes are found
            if (minIndexNewImp == -1) break;
            visitedNewImp[minIndexNewImp] = true; // Mark the node as visited

            // Update distances for adjacent nodes
            for (int j = 0; j < graph.numVerticesNewImp; ++j) {
                if (graph.adjMatrixNewImp[minIndexNewImp][j] != INT_MAX && !visitedNewImp[j]) {
                    int newDistNewImp = distNewImp[minIndexNewImp] + graph.adjMatrixNewImp[minIndexNewImp][j];
                    // If a shorter path is found, update the distance and previous node
                    if (newDistNewImp < distNewImp[j]) {
                        distNewImp[j] = newDistNewImp;
                        prevNewImp[j] = minIndexNewImp;
                    }
                }
            }
        }

        // If the end node is unreachable, print a message
        if (distNewImp[end] == INT_MAX) {
            cout << "No path exists from " << start << " to " << end << endl;
            return;
        }

        // Print the cost of the shortest path
        cout << "Shortest path cost: " << distNewImp[end] << endl;
        cout << "Path: ";
        vector<int> pathNewImp;
        // Reconstruct the path from the end node to the start node
        for (int atNewImp = end; atNewImp != -1; atNewImp = prevNewImp[atNewImp]) {
            pathNewImp.push_back(atNewImp);
        }
        // Print the path in the correct order (from start to end)
        for (int i = pathNewImp.size() - 1; i >= 0; --i) {
            cout << pathNewImp[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int numVerticesNewImp, numEdgesNewImp;
    cout << "Enter the number of nodes: ";
    cin >> numVerticesNewImp; // Get the number of nodes from the user
    cout << "Enter the number of edges: ";
    cin >> numEdgesNewImp; // Get the number of edges from the user

    NewImpGraph graph(numVerticesNewImp); // Create a graph with the given number of nodes

    // Get edge information from the user
    cout << "Enter the edges in the format (u v weight):" << endl;
    for (int i = 0; i < numEdgesNewImp; ++i) {
        int uNewImp, vNewImp, weightNewImp;
        cin >> uNewImp >> vNewImp >> weightNewImp; // Read vertices and weight for each edge
        graph.addEdgeNewImp(uNewImp, vNewImp, weightNewImp); // Add the edge to the graph
    }

    int startNodeNewImp, endNodeNewImp;
    cout << "Enter start node: ";
    cin >> startNodeNewImp; // Get the start node for Dijkstra's algorithm from the user
    cout << "Enter end node: ";
    cin >> endNodeNewImp; // Get the end node for Dijkstra's algorithm from the user

    NewImpDijkstra dijkstraNewImp;
    // Compute and display the shortest path and its cost using Dijkstra's algorithm
    dijkstraNewImp.shortestPathNewImp(graph, startNodeNewImp, endNodeNewImp);

    return 0;
}
