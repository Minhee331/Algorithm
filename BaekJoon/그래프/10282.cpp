#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 10000000;
int n;
vector<pair<int, int> > edge[100001]; // 간선 정보
int cost[100001]; //최소 비용

void dijkstra(int start){
	int sum = 0, lastCom = 0;
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
	for(int i=1; i<=n; i++){
		if(cost[i] != INF){ //cost가 INF가 아니라면  
			sum++; //감염되는 컴퓨터수 +1 
			if(lastCom < cost[i]){ // 마지막 컴퓨터가 감염되기까지 걸리는 시간
				lastCom = cost[i];
			}  
		}
	} 
	cout<<sum<<" "<<lastCom<<endl; //출력  
}

int main(void){
	int t;
	cin>>t; //테스트케이스 개수 입력  
	for(int k=0; k<t; k++){
		int d,c; 
		cin>>n>>d>>c; // 컴퓨터 개수 n, 의존성 개수d, 해킹당한 컴퓨터 번호 c 
		for(int i=1; i<=n; i++){ //초기비용은 모두 무한대로 초기화한다.  
			cost[i] = INF;
			edge[i].clear(); //초기화  
		}
		//간선정보를 입력받는다.  
		for(int i=0; i<d; i++){
			int a,b,s;
			cin>>a>>b>>s;
			edge[b].push_back(make_pair(a,s));
		}
		dijkstra(c); //다익스트라 함수 호출  
	}
}
