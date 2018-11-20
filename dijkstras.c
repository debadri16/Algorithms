#include<stdio.h>
#include<limits.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool sptSet[]){
	
	int index,v, min = INT_MAX;
	
	for(v=0;v<V;v++){
		
		if(dist[v] <= min && sptSet[v] == false){
			index = v, min = dist[v];
		}
	}
	return(index);
}

int printSolution(int dist[], int n) 
{ 
	int i;
   printf("Vertex   Distance from Source\n"); 
   for (i = 0; i < V; i++) 
      printf("%d    %d\n", i, dist[i]); 
} 

void dijkstra(int graph[][V], int src){
	
	int u,v,i,dist[V];
	bool sptSet[V];
	
	for(i=0;i<V;i++){
		dist[i] = INT_MAX, sptSet[i] = false;
	}
	
	dist[src] = 0;
	
	for(i=0;i<V-1;i++){
		
		u = minDistance(dist, sptSet);
		
		sptSet[u] = true;
		
		for(v=0;v<V;v++){
			
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
			
		}
		
	}
	printSolution(dist, V);
}

int main(){
	
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    dijkstra(graph, 0); 
	
	return 0;
}
