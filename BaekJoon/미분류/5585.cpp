#include <iostream>
using namespace std;
int main(){
	int m, cnt = 0, flag = 0, d = 500;
	cin>>m;
	m = 1000-m;
	while(m!=0){
		if(m<d){
			if(flag == 0){
				d /= 5;
				flag = 1;
			}else{
				d /= 2;
				flag = 0;
			}
		}else{
			m -= d;
			cnt++;
		}
	}
	cout<<cnt;
}
