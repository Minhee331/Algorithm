#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void bucketSort(float arr[], int n){
	vector<float> bucket[n];
	int i, j;
	for(i=0; i<n; i++){
		int b_idx = n*arr[i];
		bucket[b_idx].push_back(arr[i]);
	}
	for(int i = 0; i<n; i++){
		sort(bucket[i].begin(), bucket[i].end());
	}
	int idx = 0;
	for(i=0; i<n; i++){
		for(j=0; j<bucket[i].size(); j++){
			arr[idx++] = bucket[i][j];
		}
	}
}
int main(){
	float arr[10] = {0.785, 0.331, 0.845, 0.8181, 0.211, 0.342, 0.655, 0.788, 0.001, 0.3144};
	bucketSort(arr, 10);
	for (int i = 0; i < sizeof(arr) / sizeof(float); i++) {
        printf("%f ", arr[i]);
    }
    return 0;
}
