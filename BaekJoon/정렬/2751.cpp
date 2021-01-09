#include<iostream>
using namespace std;
int main(){
	int i, j, temp, c, root, n;
	cin>>n;
	int *heap = new int[n];
	for(i=0; i<n; i++){
		cin>>heap[i];	
	}
	for(i=1; i<n; i++){
		c = i;
		do{
			int root = (c-1)/2;
			if(heap[root]<heap[c]){
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		}while(c != 0);
	}
	for(i = n-1; i >= 0; i--){
		temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		root = 0;
		c = 1;
		do{
			c = 2 * root + 1;
			if(c < i-1 && heap[c] < heap[c+1]){
				c++;
			}
			if(c < i && heap[root] < heap[c]){
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		}while(c<i);
	}
	for(int i = 0; i < n; i++){
		cout<<heap[i]<<"\n";
	}
	return 0;	
}
