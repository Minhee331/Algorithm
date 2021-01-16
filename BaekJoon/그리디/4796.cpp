#include <iostream>
using namespace std;
int main(){
	//캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있다. 강산이는 이제 막 V일짜리 휴가를 시작했다.  
	int l, p, v, cnt = 1, max_day = 0; //max_day: 캠핑장 최대 사용 일수 , cnt : 몇 번째 케이스인지 센다.  
	while(1){
		cin>>l>>p>>v;
		if(l==0&&p==0&&v==0){
			break; //만약 l,p,v모두 0이라면 프로그램 종료  
		}
		while(v >= p){ //휴가 남은 일수(v)가 캠핑 연속일수보다 크다면,  
			v -= p; //남은 일수에서 연속일수를 뺀다.  
			max_day += l; //캠핑장 사용일수 + l 
		}
		if(v<l){ //휴가 남은 일수가 l보다 작다면  
			max_day += v; //캠핑장 사용일수에 v를 더하고,  
		}else{ //휴가 남은 일수가 l보다 크다면,  
			max_day += l; //캠핑장 사용일수에 l을 더한다.  
		}
		cout<<"Case "<<cnt<<": "<<max_day<<endl; //캠핑장 최대 사용 일수 출력 
		cnt++; //case +1
		max_day = 0; //새로운 케이스가 시작되기 때문에최대 사용 일수를 초기화 
	}
} 
