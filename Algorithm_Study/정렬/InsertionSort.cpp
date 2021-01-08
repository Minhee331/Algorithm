#include <iostream>
using namespace std;
//Insertion Sort
int main(){
	int i, j, temp;
	int arr[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7};
	for(i = 1; i < 10; i++){
		j = i;
		while(j > 0 && arr[j-1] > arr[j]){
			temp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
	for(int i = 0; i < 10; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
