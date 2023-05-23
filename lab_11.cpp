#include <iostream>
#include <climits>

using namespace std;

#define V 6  // Number of vertices in the graph

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to construct and print MST for a graph represented using an adjacency matrix
void primMST(int graph[V][V])
{
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; ++i)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;      // Make the key 0 so that this vertex is picked as the first vertex
    parent[0] = -1;  // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; ++count)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key values of the adjacent vertices of the picked vertex
        // Consider only those vertices that are not yet included in the MST
        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "Edge\n";
    cout << endl;
    for (int i = 1; i < V; ++i)
    {
        cout <<"("<< parent[i] << ","<< i <<")"<< endl;
    }
}



int main()
{
    // Example graph represented using an adjacency matrix
    int graph[V][V] = {
        {0, 3, 0, 0, 0,1},
        {3, 0, 2, 1, 10,0},
        {0, 2, 0, 3, 0,5},
        {0, 1, 3, 0, 5,0},
        {0, 10, 0, 5, 0,4},
        {1, 0 , 5, 0, 4, 0}
    };

    // Call the Prim's MST algorithm with starting node 0
    primMST(graph);

    return 0;
}
