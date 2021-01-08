#include <iostream>
using namespace std;
//Bubble Sort
int main(){
	int i, j, temp;
	int arr[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7};
	for(i = 0; i < 10; i++){
	 	for(j = 0; j < 9-i; j++){
	 		if(arr[j] > arr[j+1]){
	 			temp = arr[j];
	 			arr[j] = arr[j+1];
	 			arr[j+1] = temp;
			 }
		 }
	}
	for(i = 0; i < 10; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
