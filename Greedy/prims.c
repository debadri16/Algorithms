#include<stdio.h>
#include<limits.h>
#include <stdbool.h>

#define V 5

int extract_min(bool mstSet[V],int key[V])
{
	int i,min=INT_MAX,min_index;
	for(i=0;i<V;i++)
	{
		if(key[i]<min && mstSet[i]==false)
			{
				min=key[V];
				min_index=i;
			}
	}
	return(min_index);
}

int printMst(int parent[],int graph[V][V])
{
	int i;
    printf("Edge   Weight\n");
    for (i = 1; i < V; i++)
    	printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void prim(int graph[V][V])
{
	int i,j,u;
	bool mstSet[V];			//keeps track of vertices included in the MST
	int key[V];				//key values of vertices
	int parent[V];			//set of included vertices (parents)
	
	for(i=0;i<V;i++)
	{
		mstSet[i]=false;
		key[i]=INT_MAX;
	}
	
	key[0]=0;
	parent[0]=INT_MIN;		//initial vertex is the root
	
	for(i=0;i<V;i++)
	{
		u=extract_min(mstSet,key);
		mstSet[u]=true;		//including vertex to MST
		
		for(j=0;j<V;j++)
		{
			if(graph[i][j]<key[j] && mstSet[j]==false && graph[i][j])
				parent[j]=i,key[j]=graph[i][j];
		}
	}
	printMst(parent,graph);
}

main()
{
	/* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
            
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
                     
    prim(graph);
}
