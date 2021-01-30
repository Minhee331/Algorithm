#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char grid[100][100]; //그리드 정보 
char visited[100][100] = {0,}; //방문 처리 
int n; //그리드 크기 

void BFS(int x, int y, int f){ //f: 적록색약을 구분. 1이면 적록색약 
	int xx[4] = {0, -1, 0, 1}; // 상하좌우 탐색 시도 
	int yy[4] = {1, 0, -1, 0};
	queue<pair<int, int> > q; //queue 선언
	q.push(make_pair(y, x)); //queue에 시작점을 넣는다.
	visited[y][x] = 1;
	if(grid[y][x]=='R'&& f == 1){ //적록색약이라면 빨간색 -> 초록색 으로 바꿈 
		grid[y][x] = 'G';
	}
	char memo = grid[y][x]; //memo = 같은 구역을 탐색해야 하기 때문에 RGB중 하나를 저장 
	
	while(!q.empty()){ //q가 empty가 아닐때까지 반복 
		int currentY = q.front().first; //q의 맨 앞부분 Y을 current에 저장
		int currentX = q.front().second; //q의 맨 앞부분X을 current에 저장 
		q.pop(); //pop 
		
		for(int i=0; i<4; i++){
			int nextY = currentY + yy[i]; //좌표 업데이트  
			int nextX =  currentX + xx[i]; //좌표 업데이트 
			if(grid[nextY][nextX]=='R' && f ==1){  //적록색약이라면 빨간색 -> 초록색 으로 바꿈 
				grid[nextY][nextX] = 'G';
			}
			if( (nextX>=0 && nextX< n) && (nextY>=0 && nextY<n) && grid[nextY][nextX]== memo &&visited[nextY][nextX]==0){ //만약 업데이트된 좌표가 존재하는 좌표이고, 그리드 좌표가 memo와 같은 구역이고, 방문하지 않았던  좌표이면,  
				q.push(make_pair(nextY, nextX)); //q에 다음 좌표를 넣어준다.  
				visited[nextY][nextX] = 1; //해당 좌표 방문 처리  
			} 
		}
	}
}

int main(){
	int cnt = 0; //적록색약이 아닌 사람이 봤을 때의 구역의 수  
	int cnt_f = 0; //적록색약인 사람이 봤을 떄의 구역의 수  
	scanf("%d", &n); //그리드의 크기를 입력받는다.   
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %c", &grid[i][j]); 
		}
	}
	//적록색약이 아닌 사람이 봤을 때의 구역의 수를 구함 
	for(int i=0; i<n; i++){ 
		for(int j=0; j<n; j++){
			if(visited[i][j]==0){ //만약 방문하지 않은 그리드가 있다면, 그곳부터 BFS탐색을 시작 
				BFS(j,i,0);
				cnt++; //구역의 수++ 
			}
		}
	}
	//적록색약인 사람이 봤을 떄의 구역의 수를 구함 
	fill(visited[0], visited[100], 0); //방문 처리를 0으로 초기화 
	for(int i=0; i<n; i++){ 
		for(int j=0; j<n; j++){
			if(visited[i][j]==0){ //만약 방문하지 않은 그리드가 있다면, 그곳부터 BFS탐색을 시작 
				BFS(j,i,1);
				cnt_f++; //구역의 수++ 
			}
		}
	}
	printf("%d %d\n", cnt, cnt_f);
}
