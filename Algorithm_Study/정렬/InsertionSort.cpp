#include <iostream>
using namespace std;
//Insertion Sort
int main(){
	int arr[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7};
	int i, j, key;
	for(i = 1; i < 10; i++){
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
	for(int i = 0; i < 10; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
