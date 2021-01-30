#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int field[50][50] ={0,}; //배추밭 정보 
int visited[50][50] = {0,}; //방문 처리 
int m, n; //재추밭의 가로길이 m, 세로길이 n; 

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
			if( (nextX>=0 && nextX< n) && (nextY>=0 && nextY<m) && field[nextY][nextX] &&visited[nextY][nextX]==0){ //만약 업데이트된 좌표가 존재하는 좌표이고, 해당 밭 좌표에 양배추가 심어져있고, 방문하지 않았던  좌표이면,  
				q.push(make_pair(nextY, nextX)); //q에 다음 좌표를 넣어준다.  
				visited[nextY][nextX] = 1; //해당좌표 방문 처리  
			} 
		}
	}
}

int main(){
	int t, k; //t: 테스트 케이스, k: 배추가 심어져있는 위치의 개수 
	int x, y; //배추의 위치 x,y 
	scanf("%d", &t); //테스트 케이스 개수 입력 
	for(int l=0; l<t; l++){//
		int cnt = 0; //배추흰지렁이 마리수 
		scanf("%d%d%d", &m, &n, &k); //배추밭의 가로, 세로 크기를 입력받는다.   
		for(int i=0; i<k; i++){
			scanf("%d%d", &x, &y);
			field[x][y] = 1;
		}
		for(int i=0; i<m; i++){ 
			for(int j=0; j<n; j++){
				if(visited[i][j] == 0 && field[i][j]==1){ //만약 방문하지 않은 밭이고, 배추가 심어져있다면,  
					BFS(j,i);
					cnt++; //배추흰지렁이 수 ++ 
				}
			}
		}
		fill(visited[0], visited[50], 0); //방문 처리를 0으로 초기화  
		fill(field[0], field[50], 0); //배추밭도 0으로 초기화  
		printf("%d\n", cnt);
	}
}
