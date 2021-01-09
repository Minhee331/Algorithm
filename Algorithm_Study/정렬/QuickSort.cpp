#include<iostream>
using namespace std;

void quickSort(int arr[], int start, int end){
	
	if(start >= end){ //원소가 1개인 경우 리턴 
		return;
	}
	int pivot = start; //pivot은 start위치의 원소로 둔다. 
	int left = start+1;
	int right = end;
	int temp;
	while(left<=right){ //left와 right가 교차할 떄까지 반복한다. 
		while(left<=end && arr[left] <= arr[pivot]){ //pivot보다 큰 값을 만날때까지 left++ 
			left++;
		}
		while(right>start && arr[right] >= arr[pivot]){ //pivot보다 작은 값을 만날때까지 right-- 
			right--;
		}
		if(left>right){ //left와 right가 교차된 상태면 pivot값과 right값을 swap 
			temp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = temp;
		}else{ //교차되지 않았다면 left와 right 값을 swap 
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		quickSort(arr, start, right-1); //앞부분 정렬
		quickSort(arr, right+1, end); //뒷부분 정렬  
	}
}
int main(){
	int arr[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7}; //정렬할 배열 
	quickSort(arr, 0, 9); //quickSort함수 호출(0 ~ n-1 범위) 
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]); //정렬된 배열을 출력 
    }
    return 0;
}
