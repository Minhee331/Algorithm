#include <iostream>
using namespace std;
//merge Sort
void mergeSort(int arr[], int left, int right) {
    int temp[10000];
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;
    if (left >= right) return; 
    mergeSort(arr, left, mid); 
    mergeSort(arr, mid + 1, right); 
    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
        	temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
		}
    }
    while(i <= mid){
    	temp[k++] = arr[i++]; 
	}
    while(j <= right){
    	temp[k++] = arr[j++];
	}
    for(i = left; i <= right; i++){
    	arr[i] = temp[i];	
	}
}
 
int main() {
    int arr[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7};
    mergeSort(arr, 0, sizeof(arr) / sizeof(int)-1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

