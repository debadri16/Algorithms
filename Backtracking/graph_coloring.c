#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define V 4

void printSolution(int color[]) 
{ 
	int i;
    printf("Solution Exists:"
            " Following are the assigned colors \n"); 
    for (i = 0; i < V; i++) 
      printf(" %d ", color[i]); 
    printf("\n"); 
} 

bool isSafe(int v,bool graph[V][V],int color[],int c){
	int i;
	for(i=0;i<V;i++){
		if(graph[v][i] && color[i] == c)
			return false;
	}
	return true;
}

bool graphColoringUtil(bool graph[V][V],int m,int color[], int v){
	
	int i,j;
	if(v == V)
		return true;
		
	for(i=1;i<=m;i++){
		
		if(isSafe(v,graph,color,i)){
			
			color[v] = i;
			
			if(graphColoringUtil(graph,m,color,v + 1) == true)
				return true;
			
			color[v] = 0;
		}
		
	}
	
	return false;
}

bool graphColoring(bool graph[V][V], int m) 
{ 
    int i,color[V]; 
    for (i = 0; i < V; i++) 
       color[i] = 0; 
  
    // Call graphColoringUtil() for vertex 0 
    if (graphColoringUtil(graph, m, color, 0) == false) 
    { 
      printf("Solution does not exist"); 
      return false; 
    } 
  
    // Print the solution 
    printSolution(color); 
    return true; 
} 

int main(){
	
	bool graph[V][V] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    };
        
    int m = 3; // Number of colors 
    graphColoring (graph, m); 
	
	return 0;
}
