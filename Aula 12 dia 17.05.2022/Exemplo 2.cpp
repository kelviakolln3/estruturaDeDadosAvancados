// C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
// of a given connected, undirected and weighted graph 
#include <bits/stdc++.h> 
using namespace std; 

// a structure to represent a weighted edge in graph 
class Edge 
{ 
	public: 
	int src, dest, weight; 
}; 

// a structure to represent a connected, undirected 
// and weighted graph 
class Graph 
{ 
	public: 
	// V-> Number of vertices, E-> Number of edges 
	int V, E; 

	// graph is represented as an array of edges. 
	// Since the graph is undirected, the edge 
	// from src to dest is also edge from dest 
	// to src. Both are counted as 1 edge here. 
	Edge* edge; 
}; 

// Creates a graph with V vertices and E edges 
Graph* createGraph(int V, int E) 
{ 
	Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 

	graph->edge = new Edge[E]; 

	return graph; 
} 

// A structure to represent a subset for union-find 
class subset 
{ 
	public: 
	int parent; 
	int rank; 
}; 

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(subset subsets[], int i) 
{ 
	// find root and make root as parent of i 
	// (path compression)
	printf("\n");
	printf("Find \n");
	printf("i = %d \n", i);
	printf("subsets[i].parent = %d \n", subsets[i].parent);
	if (subsets[i].parent != i) {
	    printf("If \n");
		subsets[i].parent = find(subsets, subsets[i].parent); 
	}
    printf("return = %d \n", subsets[i].parent);
	return subsets[i].parent; 
} 

// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(subset subsets[], int x, int y) 
{ 
    printf("Union \n");
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y); 
	printf("xroot %d \n", xroot);
	printf("yroot %d \n", yroot);
	printf("subsets[yroot].parent %d \n", subsets[yroot].parent);
	printf("subsets[yroot].rank %d \n \n", subsets[yroot].rank);
	
	printf("subsets[xroot].parent %d \n", subsets[xroot].parent);
	printf("subsets[xroot].rank %d \n", subsets[xroot].rank);
	

	// Attach smaller rank tree under root of high 
	// rank tree (Union by Rank) 
	if (subsets[xroot].rank < subsets[yroot].rank){
	    printf("1 if \n");
		subsets[xroot].parent = yroot; 
		printf("subsets[yroot].parent %d \n", subsets[yroot].parent);
	    printf("subsets[yroot].rank %d \n \n", subsets[yroot].rank);
	
	    printf("subsets[xroot].parent %d \n", subsets[xroot].parent);
	    printf("subsets[xroot].rank %d \n", subsets[xroot].rank);
	}else if (subsets[xroot].rank > subsets[yroot].rank) {
		printf("2 if \n");
		subsets[yroot].parent = xroot; 
		printf("subsets[yroot].parent %d \n", subsets[yroot].parent);
	    printf("subsets[yroot].rank %d \n \n", subsets[yroot].rank);
	
	    printf("subsets[xroot].parent %d \n", subsets[xroot].parent);
	    printf("subsets[xroot].rank %d \n", subsets[xroot].rank);
	}
	// If ranks are same, then make one as root and 
	// increment its rank by one 
	else
	{ 
	    printf("3 if\n");
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
		printf("xroot %d \n", xroot);
	    printf("yroot %d \n", yroot);
	    printf("subsets[yroot].parent %d \n", subsets[yroot].parent);
	    printf("subsets[yroot].rank %d \n \n", subsets[yroot].rank);
	
	    printf("subsets[xroot].parent %d \n", subsets[xroot].parent);
	    printf("subsets[xroot].rank %d \n", subsets[xroot].rank);
	} 
} 

// Compare two edges according to their weights. 
// Used in qsort() for sorting an array of edges 
int myComp(const void* a, const void* b) 
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
} 

// The main function to construct MST using Kruskal's algorithm 
void KruskalMST(Graph* graph) 
{ 
	int V = graph->V; 
	Edge result[V]; // Tnis will store the resultant MST 
	int e = 0; // An index variable, used for result[] 
	int i = 0; // An index variable, used for sorted edges 

	// Step 1: Sort all the edges in non-decreasing 
	// order of their weight. If we are not allowed to 
	// change the given graph, we can create a copy of 
	// array of edges 
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 

	// Allocate memory for creating V ssubsets 
	subset *subsets = new subset[( V * sizeof(subset) )]; 
	printf("pesos\n");
	for(int x=0; x<5;){
		Edge next_edge = graph->edge[x++]; 
		printf("%d\t", next_edge.weight);
	}
	printf("\n");

	// Create V subsets with single elements 
	for (int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 

	// Number of edges to be taken is equal to V-1 
	while (e < V - 1 && i < graph->E) 
	{ 
		// Step 2: Pick the smallest edge. And increment 
		// the index for next iteration 
		printf("*****************************************\n");
		printf("i = %d\n",i);
		printf("e = %d\n",e);
		Edge next_edge = graph->edge[i++]; 
        printf("next_edge.src = %d\n",next_edge.src);
		printf("next_edge.dest = %d\n",next_edge.dest);
		int x = find(subsets, next_edge.src); 
		int y = find(subsets, next_edge.dest); 
        printf("x: %d\n",x);
		printf("y: %d\n",y);
		// If including this edge does't cause cycle, 
		// include it in result and increment the index 
		// of result for next edge 
		if (x != y) 
		{ 
			result[e++] = next_edge;
			printf("e = %d\n",e);
			Union(subsets, x, y); 
		} 
		// Else discard the next_edge 
		printf("==============================================\n");
	} 

	// print the contents of result[] to display the 
	// built MST 
	cout<<"Following are the edges in the constructed MST\n"; 
	for (i = 0; i < e; ++i) {
		printf("i = %d\n", i);
		cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;
	}
	return; 
} 

// Driver code 
int main() 
{ 
	/* Let us create following weighted graph 
			10 
		0--------1 
		|      \ | 
	  6|     5\ |15 
		|      \ | 
		2--------3 
			4 */
	int V = 4; // Number of vertices in graph 
	int E = 5; // Number of edges in graph 
	Graph* graph = createGraph(V, E); 


	// add edge 0-1 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 
	graph->edge[0].weight = 10; 

	// add edge 0-2 
	graph->edge[1].src = 0; 
	graph->edge[1].dest = 2; 
	graph->edge[1].weight = 6; 

	// add edge 0-3 
	graph->edge[2].src = 0; 
	graph->edge[2].dest = 3; 
	graph->edge[2].weight = 5; 

	// add edge 1-3 
	graph->edge[3].src = 1; 
	graph->edge[3].dest = 3; 
	graph->edge[3].weight = 15; 

	// add edge 2-3 
	graph->edge[4].src = 2; 
	graph->edge[4].dest = 3; 
	graph->edge[4].weight = 4; 

	KruskalMST(graph); 

	return 0; 
} 

// This code is contributed by rathbhupendra 
/*
v = 0
subsets[0].parent = 2
subsets[0].rank = 1
—------------------------------
v = 1
subsets[1].parent = 2
subsets[1].rank = 0
—-----------------------------
v = 2
subsets[2].parent = 2 
subsets[2].rank = 1
—-------------------------------
v = 3
subsets[3].parent = 2
subsets[3].rank = 0*/

