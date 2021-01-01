#include <iostream>
using namespace std;

int main(){
	int arr[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7};
	int temp;
	for(int i = 0; i < 10; i++){
	 	for(int j = 0; j < 9-i; j++){
	 		if(arr[j] > arr[j+1]){
	 			temp = arr[j];
	 			arr[j] = arr[j+1];
	 			arr[j+1] = temp;
			 }
		 }
	}
	for(int i = 0; i < 10; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
