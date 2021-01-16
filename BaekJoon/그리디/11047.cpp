#include <iostream>
using namespace std;
int main(){
	int n, k, i, cnt = 0; //n: 준석이가 가지고있는 동전 수 k: 만드려는 가치의 합, cnt: 동전개수의 최소값  
	cin>>n>>k;
	int *value = new int[n]; //동전의 가치를 저장할 배열을 동적할당  
	for(i = 0; i<n; i++){
		cin>>value[i];
	}
	for(i = n-1; i>=0; i--){
		if(k>=value[i]){ //만약 목표 가치 합보다 동전의 가치(value[i])가 크다면  
			k-=value[i]; //목표 가치 합에서 동전의 가치를 빼고,  
			cnt++; //동전 개수를 1 올린다.  
			i++; //목표 가치 합보다 동전의 가치(value[i])가 큰지 다시 확인하기 위해 for문을 돈다.  
		}
	}
	cout<<cnt;
} 
