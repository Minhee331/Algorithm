#include <iostream>
using namespace std;
//2750
int main(){
	int n;
//	int i, j, temp;
	int i, j, key;
	cin>>n;
	int *arr = new int[n];
	for(i = 0; i < n; i++){
		cin>>arr[i];
	}
	//bubble Sort 
//	for(i = 0; i < n; i++){
//	 	for(j = 0; j < n-1-i; j++){
//	 		if(arr[j] > arr[j+1]){
//	 			temp = arr[j];
//	 			arr[j] = arr[j+1];
//	 			arr[j+1] = temp;
//			 }
//		 }
//	}
	//insertion sort 
	for(i = 1; i < n; i++){
		key = arr[i];
		for(j = i - 1; j >= 0; j--){
			if(arr[j] > key){
				arr[j+1] = arr[j];
			}else{
				break;
			}
		}
		arr[j+1] = key;
	}
	for(i = 0; i < n; i++){
		cout<<arr[i]<<"\n";
	}
	return 0;
}
