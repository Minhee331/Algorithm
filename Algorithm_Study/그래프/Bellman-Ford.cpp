#include <iostream> 
  
struct Edge { 
    int src, dest, weight; 
}; 
  
struct Graph { 
    int V, E; //V: 정점 E: 간선  
    struct Edge* edge; //그래프는 간선 배열로 나타냄 
}; 
//정점과 간선이 있는 그래프 생성  
struct Graph* createGraph(int V, int E) 
{ 
    struct Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
} 
// 결과 프린트 
void printArr(int dist[], int n) 
{ 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
//벨만포드 
void BellmanFord(struct Graph* graph, int src) 
{ 
    int V = graph->V; 
    int E = graph->E; 
    int dist[V]; 
    
    for (int i = 0; i < V; i++){//정점들까지의 거리를 무한대로 초기화 
    	dist[i] = INT_MAX; 
	}
    dist[src] = 0; //시작점은 0으로 초기화  
  
    for (int i = 1; i <= V - 1; i++) { 
        for (int j = 0; j < E; j++) { 
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) //u가 무한대가 아니고, 최단거리 + 가중치가 v의 가중치보다 작으면 업데이트  
                dist[v] = dist[u] + weight; 
        } 
    } 
  	
    for (int i = 0; i < E; i++) { //음의 가중치가 있는지 확인 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { //최단거리 + 가중치가 작아질 경우 
            printf("Graph contains negative weight cycle"); 
            return; //음의 사이클이 감지될 시 리턴 
        } 
    } 
    printArr(dist, V); 
    return; 
} 

int main() 
{ 
    int V = 5; // 정점 수  
    int E = 8; // 간선 수  
    struct Graph* graph = createGraph(V, E); 
    
    //0->1로 가는 간선, 가중치 추가  
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
  
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  
    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  
    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  
    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  
    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
  
    BellmanFord(graph, 0); 
  
    return 0; 
} 
