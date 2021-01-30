#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > edge[7]; // 간선 정보
int cost[7]; //최소 비용

void dijkstra(int start){
	cost[start] = 0;
	priority_queue<pair<int, int> > pq; //우선순위 큐 선언
	pq.push(make_pair(start, 0));
	while(!pq.empty()){ //만약 큐가 비어있지 않다면 계속 반복 
		int current = pq.top().first; //current에 현재 큐의 top을 저장  
		int distance = -pq.top().second; //짧은 것이 먼저 오도록 음수화  
		pq.pop(); //pop 
		if(cost[current] < distance){ //최단 경우가 아닌경우 continue
			continue;
		}
		for(int i = 0; i<edge[current].size(); i++){
			int next = edge[current][i].first; //현재 노드의 인접한 노드 next 
			int nextDistatnce = distance + edge[current][i].second; //현재 노드를 인접 노드 next로 거쳐 가는 비용  
			if(nextDistatnce < cost[next]){ //기존 비용과 비교해 작다면, 최소비용 교체  
				cost[next] = nextDistatnce;
				pq.push(make_pair(next, -nextDistatnce)); //큐에 push  
			}
		}
	} 
}

int main(void){
	for(int i=1; i<=number; i++){ //초기비용은 모두 무한대로 초기화한다.  
		cost[i] = INF;
	}
	//간선정보를 입력받는다.  
	edge[1].push_back(make_pair(2, 7));
	edge[1].push_back(make_pair(3, 9));
	edge[1].push_back(make_pair(6, 14));
	
	edge[2].push_back(make_pair(1, 7));
	edge[2].push_back(make_pair(3, 10));
	edge[2].push_back(make_pair(4, 15));
	
	edge[3].push_back(make_pair(1, 9));
	edge[3].push_back(make_pair(2, 10));
	edge[3].push_back(make_pair(4, 11));
	edge[3].push_back(make_pair(6, 2));
	
	edge[4].push_back(make_pair(2, 15));
	edge[4].push_back(make_pair(3, 11));
	edge[4].push_back(make_pair(5, 6));
	
	edge[5].push_back(make_pair(4, 6));
	edge[5].push_back(make_pair(6, 9));
	
	edge[6].push_back(make_pair(1, 14));
	edge[6].push_back(make_pair(3, 2));
	edge[6].push_back(make_pair(5, 9));
	
	dijkstra(1);
	for(int i=1; i<=number; i++){
		printf("%d ", cost[i]);
	}
}
