#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 8; //노드의 개수
int visited[8]; //방문 체크
vector<int> node[9]; // node 가 숫자 1부터 들어갈 수 있도록 8로 생성 

void BFS(int start){
	queue<int> q; //queue 선언
	q.push(start); //queue에 시작점을 넣는다. 
	visited[start] = true;//방문하면 true 
	while(!q.empty()){ //q가 empty가 아닐때까지 반복 
		int current = q.front(); //q의 맨 앞부분을 current에 저장 
		q.pop(); //pop 
		printf("%d ", current); //current를 출력 
		for(int i=0; i<node[current].size(); i++){ //current 에 인접한 node를 방문한다.  
			int next = node[current][i]; //current 와 인접한 node인 next 
			if(!visited[next]){ //방문하지 않은 노드라면 
				q.push(next); //q에 next를 넣어준다. 
				visited[next] = true; //방문처리  
			}
		}
	}
}

int main(){
	//각 노드를 연결한다.  
	node[1].push_back(2);
	node[2].push_back(1);
	
	node[1].push_back(3);
	node[3].push_back(1);
	
	node[2].push_back(4);
	node[4].push_back(2);
	
	node[2].push_back(5);
	node[5].push_back(2);
	
	node[3].push_back(6);
	node[6].push_back(3);
	
	node[3].push_back(7);
	node[7].push_back(3);
	
	node[5].push_back(8);
	node[8].push_back(5);
	
	BFS(1); //bfs 수행
	return 0;  
} 
