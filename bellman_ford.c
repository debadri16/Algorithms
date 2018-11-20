#include<stdio.h>
#include<stdlib.h>

struct Edge{
	int src,dest,weight;
};

struct Graph{
	int V,E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
	
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->E = E;
	graph->V = V;
	graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
	
	return(graph); 

}

void printArr(int dist[], int n) 
{ 
	int i;
    printf("Vertex   Distance from Source\n"); 
    for (i = 0; i < n; ++i) 
        printf("%d    %d\n", i, dist[i]); 
}

void BellmanFord(struct Graph* graph,int src){
	
	int i,j,u,v,weight;
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	
	for (i = 0; i < V; i++) 
        dist[i] = INT_MAX; 
    dist[src] = 0;
    
    for(i=1;i<=V-1;i++){
    	
    	for(j=0;j<E;j++){
    		
    		u = graph->edge[j].src;
    		v = graph->edge[j].dest;
    		weight = graph->edge[j].weight;
    		
    		if((dist[u]+weight < dist[v]) && dist[u] != INT_MAX)
    			dist[v] = dist[u]+weight;
		}
    	
	}
	
	//cycle detection
	for(i=0;i<E;i++){
		u = graph->edge[i].src;
		v = graph->edge[i].dest;
		weight = graph->edge[i].weight;
		
		if(dist[u]+weight < dist[v] && dist[u] != INT_MAX)
			printf("Graph contains negative weight cycle");
	}
	
	printArr(dist, V);
	
}

int main(){
	
	int V = 5;  // Number of vertices in graph 
    int E = 8;  // Number of edges in graph 
    struct Graph* graph = createGraph(V, E); 
  
    // add edge 0-1 (or A-B in above figure) 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
  
    BellmanFord(graph, 0); 
	
	return 0;
}
