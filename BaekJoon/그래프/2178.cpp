#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int maze[100][100]; //미로 정보 
int visited[100][100] = {0,}; //시작점으로부터의 거리
int n, m; //행, 열 

void BFS(int x, int y){
	int xx[4] = {0, -1, 0, 1}; // 상하좌우 탐색 시도 
	int yy[4] = {1, 0, -1, 0};
	queue<pair<int, int> > q; //queue 선언
	q.push(make_pair(y, x)); //queue에 시작점을 넣는다.
	visited[y][x] = 1;
	
	while(!q.empty()){ //q가 empty가 아닐때까지 반복 
		int currentY = q.front().first; //q의 맨 앞부분 Y을 current에 저장
		int currentX = q.front().second; //q의 맨 앞부분X을 current에 저장 
		q.pop(); //pop 
		
		for(int i=0; i<4; i++){
			int nextY = currentY + yy[i]; //좌표 업데이트  
			int nextX =  currentX + xx[i]; //좌표 업데이트 
			if( (nextX>=0 && nextX< m) && (nextY>=0 && nextY<n) && maze[nextY][nextX]==1 &&visited[nextY][nextX]==0){ //만약 업데이트된 좌표가 존재하는 좌표이고, 미로좌표가 1(방문 가능),방문하지 않았던  좌표이면,  
				q.push(make_pair(nextY, nextX)); //q에 다음 좌표를 넣어준다.  
				visited[nextY][nextX] = visited[currentY][currentX] + 1; //거리 + 1 
			} 
		}
	}
}

int main(){
	scanf("%d%d", &n, &m); //미로의 가로 n, 세로 m을 입력받는다.   
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &maze[i][j]); 
		}
	}
	BFS(0, 0); 
	printf("%d\n", visited[n-1][m-1]);
}
