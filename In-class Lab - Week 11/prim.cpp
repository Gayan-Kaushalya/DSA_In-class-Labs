#include <bits/stdc++.h>
using namespace std;

#define num_of_poles 6

// Prim's algorithm
void prim(int graph[num_of_poles][num_of_poles], int source){
	// This array will store the constructed minimum spanning tree.
	int parent[num_of_poles];

	// This array will store key values used to pick the minimum weight edge in the cut.
	int key[num_of_poles];

	// This array will represent set of vertices included in the minimum spanning tree.
	bool included_in_MST[num_of_poles];

	// Initializing all keys as infinity
	for (int i = 0; i < num_of_poles; i++){
		key[i] = INT_MAX;
        included_in_MST[i] = false;
    }

	// Making key of source node as 0 so that it is picked as first vertex
	key[source] = 0;

    // Source node is the root of the minimum spanning tree.
	parent[source] = -1;

	for (int count = 0; count < num_of_poles - 1; count++) {		
		// Picking the vertex with minimum key value from the set of vertices which are not yet included in minimum spanning tree
        int min = INT_MAX, min_index;

	    for (int x = 0; x < num_of_poles; x++){
		    if (included_in_MST[x] == false && key[x] < min){
			    min = key[x]; 
                min_index = x;
            }
        }

		// Adding the picked vertex to the minimum spanning tree
		included_in_MST[min_index] = true;

		// Updating key values and parent indices of the adjacent vertices of the picked vertex
		// Here we only consider the vertices which are not yet included in minimum spanning tree.
		for (int y = 0; y < num_of_poles; y++){

			// graph[min_index][y] is non zero only when there is a edge between Node (min_index) and Node (y).
			// included_in_MST[y] is false when Node (y) is not yet included in the minimum spanning tree.
			// Key is updated only if graph[min_index][y] is smaller than key[y].

			if (graph[min_index][y] && included_in_MST[y] == false && graph[min_index][y] < key[y]){                
				parent[y] = min_index; 
                key[y] = graph[min_index][y];
            }
        }
	}

	// Printing the minimum spanning tree
	cout << " Edge   Weight" << endl;
	for (int i = 0; i < num_of_poles; i++){
        if (i != source){
			cout << parent[i] << " - " << i << "     " << graph[i][parent[i]] << endl;
        }
    }
}


int main(){
    // Initializing adjacency matrix
	int adj[num_of_poles][num_of_poles] = { 
        { 0,  3, 0, 0,  0, 1},
	{ 3,  0, 2, 1, 10, 0},   
        { 0,  2, 0, 3,  0, 5},
        { 0,  1, 3, 0,  5, 8},
        { 0, 10, 0, 5,  0, 4},
        { 1,  0, 5, 0,  4, 0}
    };

	prim(adj, 0);       // Here we can choose any node as source node. 

	return 0;
}
