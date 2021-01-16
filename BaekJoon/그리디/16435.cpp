#include <iostream>
using namespace std;
//16435번  
int main(){
	int n, l, i;//n: 과일의 개수, l: 스네이크버드 초기 길이  
	cin>>n>>l;
	int *h_arr = new int[n]; //각 과일의 높이를 저장할 배열을 동적할당  
	for(i = 0; i < n; i++){
		cin>>h_arr[i];
	}
	for(i = 0; i < n; i++){
		if(h_arr[i] <= l && h_arr[i]!=-1){ //만약 과일의 길이가 스네이크버드의 길이보다 작고, 과일의 길이가 -1(이미 먹은 과일)아 아니라면,  
			l++; //스네이크 버드가 해당 과일h_arr[i] 을 먹고 길이가 1만큼 늘어남  
			h_arr[i] = -1; //이미 먹은 과일이므로 -1로 저장  
			i = -1; //다시 배열을 처음부터(i = 0) 돌 예정  
			continue; //for 문으로 돌아감  
		}
	}
	cout<<l; //스네이크버드 최종길이 출력  
} 
