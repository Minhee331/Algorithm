#include <iostream>
using namespace std;
//2752
int main(){
	int i, j, temp;
	int arr[3];
	for(i = 0; i < 3; i++){
		cin>>arr[i];
	}
	//bubble sort 
	for(i = 0; i < 3; i++){
	 	for(j = 0; j < 2-i; j++){
	 		if(arr[j] > arr[j+1]){
	 			temp = arr[j];
	 			arr[j] = arr[j+1];
	 			arr[j+1] = temp;
			 }
		 }
	}
	for(i = 0; i < 3; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
