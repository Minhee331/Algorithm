#include <iostream>
using namespace std;
int INF = 99999999;

int arr[101][101]; //배열 초기화  

void floydWarshall(int number){ //플로이드 와샬 함수 시작  
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
	
	//케빈 베이컨 
	int idx = 0; //케빈 베이컨의 수가 가장 작은 idx를 찾기 위함 
	int min = 99999999; //최소값 min 
	for(int i=0; i<number; i++){
		int sum=0; //sum을 0으로 초기화  
		for(int j=0; j<number; j++){
			sum+=result[i][j]; //케빈베이컨 합을 구한다.  
		}
		if(sum<min){ //min보다 합이 작다면 업데이트  
			idx = i;  
			min = sum;
		}
	}
	cout<<idx+1;
} 
int main(){
	int n,m,a,b,i,j;
	cin>>n>>m;//유저의수 n, 친구 관계의 수 m 
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i!=j) arr[i][j] = INF; //친구 관계를 입력 받기전 배열 모든 값을 inf로 초기화  
		}
	}
	for(i=0; i<m; i++){
		cin>>a>>b; //친구관계 입력  
		arr[a-1][b-1] = 1; //가중치를 1로 설정
		arr[b-1][a-1] = 1;
	}
	floydWarshall(n); //플로이드 와샬  
	return 0;
}
