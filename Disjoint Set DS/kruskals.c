#include<stdio.h>
#include<stdlib.h>

struct Edge{
	int src,dest,wt;
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

//comparator function reqd for qsort
int compFunc(const void* a, const void* b){
	
	int l = ((struct Edge*)a)->wt; 
    int r = ((struct Edge*)b)->wt;
    
	return(l-r);
}

int find(int parent[], int i) 
{ 
    if (parent[i] == -1) 
        return i; 
    return parent[i]; 
}

void union_set(int parent[], int x, int y){
	int xset = find(parent, x); 
    int yset = find(parent, y); 
    if(xset!=yset){ 
       parent[xset] = yset; 
    }
}

void kruskalMst(struct Graph* graph){
	
	int i=0,j,v,e=0,x,y;
	int V = graph->V;
	struct Edge result[V];
	
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compFunc);
	
	int *parent = (int*) malloc( V * sizeof(int) ); 
	
	for(j=0;j<V;j++){
		parent[j] = -1;
	}
    
    while(e < V-1){
    	
    	struct Edge next_edge = graph->edge[i++];
    	
    	x = find(parent, next_edge.src); 
        y = find(parent, next_edge.dest);
        
        if(x != y){
        	
        	result[e++] = next_edge;
        	union_set(parent,x,y);
		}
    	
	}
	
	printf("Following are the edges in the constructed MST\n"); 
    for (i = 0; i <e ; ++i) 
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, 
                                                 result[i].wt); 
	
}

int main(){
	
	int V = 4, E = 5;
	
	struct Graph* graph = createGraph(V,E);
	
	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].wt = 10;
	
	// add edge 0-2 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].wt = 6; 
  
    // add edge 0-3 
    graph->edge[2].src = 0; 
    graph->edge[2].dest = 3; 
    graph->edge[2].wt = 5; 
  
    // add edge 1-3 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].wt = 15; 
  
    // add edge 2-3 
    graph->edge[4].src = 2; 
    graph->edge[4].dest = 3; 
    graph->edge[4].wt = 4;
    
    kruskalMst(graph);
    
	return 0;
}
