#include<iostream>
using namespace std;
int main(){
	int i, j, temp, c, root;
	int heap[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7};
	for(i=1; i<10; i++){
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
	for(i = 9; i >= 0; i--){
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
	for(int i = 0; i < 10; i++){
		cout<<heap[i]<<" ";
	}
	return 0;	
}
