#include <iostream>
using namespace std;
int main(){
	int arr[6]={0}, n, max=0;
	for(int i=0; i<3; i++){
		cin>>n;
		arr[n-1]++;
	}
	for(int i=0; i<6; i++){
		if(arr[i]==1){
			max = i;
		}
		if(arr[i]==3){
			cout<<10000+(i+1)*1000;
			return 0;
		}
		if(arr[i]==2){
			cout<<1000+(i+1)*100;
			return 0;
		}
	}
	cout<<(max+1)*100;
}
