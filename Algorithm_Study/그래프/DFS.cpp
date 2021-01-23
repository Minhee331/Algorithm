#include <iostream>
#include <vector>
using namespace std;

int number = 7;
int visited[7]; //방문 체크
vector<int> node[8]; // node 가 숫자 1부터 들어갈 수 있도록 8로 생성 
 
void DFS(int x){
	if(visited[x]){ //x노드를 방문했다면,  리턴  
		return; 
	}
	visited[x] = true; //처음 방문한 노드라면 방문처리 
	printf("%d ", x);
	for(int i=0; i<node[x].size(); i++){ //x 에 인접한 node를 방문한다.  
		int y = node[x][i]; //인접 노드에 대해 dfs를 수행한다.  
		DFS(y);
	}
}

int main(){
	//각 노드를 연결한다.  
	node[1].push_back(2);
	node[2].push_back(1);
	
	node[1].push_back(3);
	node[3].push_back(1);
	
	node[2].push_back(3);
	node[3].push_back(2);
	
	node[2].push_back(4);
	node[4].push_back(2);
	
	node[2].push_back(5);
	node[5].push_back(2);
	
	node[3].push_back(6);
	node[6].push_back(3);
	
	node[3].push_back(7);
	node[7].push_back(3);
	
	node[4].push_back(5);
	node[5].push_back(4);
	 
	node[6].push_back(7);
	node[7].push_back(6);
	
	DFS(1); //dfs 수행
	return 0;  
} 
