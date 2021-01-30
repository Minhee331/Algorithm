#include <iostream>

int number = 4;
int INF = 10000000;

int arr[4][4] = { //배열  초기화 
	{INF, INF, -2, INF},
	{4, INF, 3, INF},
	{INF, INF, INF, 2},
	{INF, -1, INF, INF}
};

void floydWarshall(){ //플로이드 와샬 함수 시작  
	int result[number][number]; //결과 그래프 
	for(int i=0; i<number; i++){ //결과 그래프를 arr그래프로 초기화  
		for(int j=0; j<number; j++){
			result[i][j] = arr[i][j];
		}
	}
	for(int k=0; k<number; k++){ //k: 거쳐가는 노드 
		for(int i=0; i<number; i++){ //i: 출발 노드  
			for(int j=0; j<number; j++){  //j: 도착 노드  
				if(result[i][k] + result[k][j] < result[i][j]){
					result[i][j] = result[i][k] + result[k][j];
				}
			}
		}
	}
	for(int i =0; i<number; i++){
		for(int j=0; j<number; j++){
			printf("%3d ", result[i][j]); //결과 그래프 출력  
		}
		printf("\n");
	}
} 
int main(){
	floydWarshall();
}
