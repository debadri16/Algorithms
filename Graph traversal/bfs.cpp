#include<iostream>
#include<list>

using namespace std;

struct Graph{
	int V;
	list<int> *adj;
};

struct Graph* createGraph(int v){
	struct Graph* graph = new Graph;
	graph->V = v;
	graph->adj = new list<int>[v];
	
	return(graph);
}

void addEdge(struct Graph* graph,int v,int w){
	graph->adj[v].push_back(w); 
}

void BFS(struct Graph* graph,int s){

	int i,V = graph->V;	
	
	list<int> *adj = graph->adj;
	
	bool visited[V];
	for(i=0;i<V;i++)
		visited[i] = 0;
	
	//queue for bfs
	list<int> queue;
	
	//current node
	visited[s] = true;
	queue.push_back(s); 
	
	list<int>::iterator j;
	
	while(!queue.empty()){
		
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		
		for(j=adj[s].begin(); j!=adj[s].end(); ++j){
			
			if(!visited[*j]){
				
				visited[*j] = true;
				queue.push_back(*j); 
				
			}
			
		}
		
	}

	
}

int main() 
{ 
	int i,v=4;
    // Create a graph given in the above diagram 
    struct Graph* graph = createGraph(v); 
    addEdge(graph,0, 1); 
    addEdge(graph,0, 2); 
    addEdge(graph,1, 2); 
    addEdge(graph,2, 0); 
    addEdge(graph,2, 3); 
    addEdge(graph,3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    BFS(graph,2);
  
    return 0; 
} 
