#include<iostream>
#include<queue>
using namespace std;
int main(){
	int i, j;
	int max = 0;
	int arr[10] = {200, 42, 151, 201, 810, 311, 645, 511, 170, 667};
	queue<int> radix[10];
	for(int i=0; i<10; i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	int maxPos = 1;
	while(max > 10){
		maxPos *= 10;
		max /= 10;
	}
	int pos = 1;
	int mod = 10;
	while(pos <= maxPos){
		for(int i=0; i<10; i++){
			radix[arr[i]%mod/pos].push(arr[i]);
		}
		for(i=0, j=0; i<10;){
			if(radix[i].size()){
				arr[j++] = radix[i].front();
				radix[i].pop();
			}else{
				i++;
			}
		}
		mod *= 10;
		pos *= 10;
	}
	for(i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
