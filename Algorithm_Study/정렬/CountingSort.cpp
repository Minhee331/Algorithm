#include <iostream>
using namespace std;
int main(){
	int i, j;
	int cnt[6]={0,};
	int arr[30] = {1,5,4,2,3,4,5,2,1,5
				  ,1,5,2,1,3,5,4,2,1,4
				  ,4,5,1,3,2,4,3,3,4,2};
	for(i=0; i<30; i++){
		cnt[arr[i]]++;
	}
	for(i=1; i<6; i++){
		if(cnt[i] != 0){
			for(j=0; j<cnt[i]; j++){
				cout<<i<<" ";
			}
		}
	}
	return 0;
}
