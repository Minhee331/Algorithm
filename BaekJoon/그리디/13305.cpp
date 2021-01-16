#include <iostream>
using namespace std;
int main(){
	int n, i; // n: 도시의 개수 
	long long cost=0, min=1000000001; // cost: 최소비용, min: 리터당가격의 최소값 
	cin>>n;	//도시의 개수를 입력받는다.  
	int *road = new int[n-1]; //두 도시 사이의 도로 길이를 저장하는 배열을 동적할당
	int *city = new int[n]; // 각 도시 주요소의 리터당 가격을 저장하는 배열을 동적할당 
	for(i=0; i<n-1; i++){
		cin>>road[i];
	}
	for(i=0; i<n; i++){
		cin>>city[i];

	}
	for(i=0; i<n-1; i++){
		if(city[i]<min){ //만약 도시의 리터당 가격의 값이 최소값(min)보다 작다면 최소값을 교체 
			min = city[i];
		}
		cost += min * road[i]; //최소비용은 리터당 가격의 최소값과 각 도로 길이를 곱한 값의 누적합. 
	}
	cout<<cost; //최소비용을 출력  
}
