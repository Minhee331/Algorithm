#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int maze[100][100];
int visited[100][100] = {0,};
int n, m;

void BFS(int x, int y){
	int xx[4] = {0, 1, 0, -1}; // 아래, 우측, 위, 좌측 순으로 탐색 시도 
	int yy[4] = {-1, 0, 1, 0};
	queue<pair<int, int> > q; //queue 선언
	q.push(make_pair(x, y)); //queue에 시작점을 넣는다.
	visited[x][y]++; 
	while(!q.empty()){ //q가 empty가 아닐때까지 반복 
		int currentX = q.front().first; //q의 맨 앞부분 x을 current에 저장
		int currentY = q.front().second; //q의 맨 앞부분y을 current에 저장 
		q.pop(); //pop 
		for(int i=0; i<4; i++){
			int nextX =  x + xx[i]; //좌표 업데이트 
			int nextY = y + yy[i]; //좌표 업데이트  
			if( (nextX>0 && nextX< n) && (nextY>0 && nextY<m)){ //만약 업데이트된 좌표가 존재하는 좌표라면,  
				q.push(make_pair(nextX, nextY)); //q에 다음 좌표를 넣어준다.  
				visited[nextX][nextY] = visited[currentX][currentY] + 1; //방문 처리 
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
	printf("%d\n", visited[n-1][m-1]+1);
}
