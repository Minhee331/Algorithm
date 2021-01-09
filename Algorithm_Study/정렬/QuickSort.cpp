#include<iostream>
using namespace std;
void quickSort(int arr[], int start, int end){
	if(start >= end){
		return;
	}
	int key = start;
	int i = start+1;
	int j = end;
	int temp;
	while(i<=j){
		while(i<=end && arr[i] <= arr[key]){
			i++;
		}
		while(j>start && arr[j] >= arr[key]){
			j--;
		}
		if(i>j){
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
		}else{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		quickSort(arr, start, j-1);
		quickSort(arr, j+1, end);
	}
}
int main(){
	int arr[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7};
	quickSort(arr, 0, 9);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
