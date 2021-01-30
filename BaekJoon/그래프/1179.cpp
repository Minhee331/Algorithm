#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define P pair<int, int>

int visited[10001]; //방문 여부 
vector<P> edge[10001]; //간선 정보  

int prim(){
	int cost= 0; //비용 
	priority_queue<P, vector<P>, greater<P> > pq; //우선순위 큐 - 
	pq.push(P(0,1)); //1번부터 시작 
	
	while(!pq.empty()){ //큐가 빌때까지 계속 반복 
		P current = pq.top(); //cur에 큐의 탑 저장 
		pq.pop(); //pop 
		if(visited[current.second]){ //이미 방문했을 경우 while문으로 돌아감 
			continue;
		}else{ //방문하지 않읐을 경우 방문 처리  
			visited[current.second] = 1;
		}  
		cost += current.first; //전체 비용을 저장  
		for(int i=0; i<edge[current.second].size(); i++){
			if(!visited[edge[current.second][i].second]){
				pq.push(edge[current.second][i]); //큐에 집어넣는다.  
			}
		}
	}
	return cost; //cost를 리턴 한다.  
}

int main(){
	int v,e; //정점의 개수 v, 간선의 개수 e 
	cin>>v>>e; //입력 
	for(int i=0; i<e; i++){
		int a,b,c; //a번 정점과 b번 정점이 가중치 c이 간선으로 연결 
		cin>>a>>b>>c;
		edge[a].push_back(P(c,b)); //a, b정점을 잇는 간선 경로 비용 c 
		edge[b].push_back(P(c,a)); //b, a정점을 잇는 간선 경로 비용 c 
	}
	cout<<prim();//비용을 출력한다.  
	return 0;
}

