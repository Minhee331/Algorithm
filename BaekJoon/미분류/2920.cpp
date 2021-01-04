#include <iostream>
using namespace std;
int main(){
	int arr[8], cnt;
	for(int i=0; i<8; i++){
		cin>>arr[i];
	}
	if(arr[0]==1){
		cnt = 2;
		for(int i=1; i<8; i++){
			if(arr[i] == cnt){
				cnt++;
			}else{
				cout<<"mixed"<<endl;
				return 0;
			}
		}
		cout<<"ascending"<<endl;
	}else if(arr[0]==8){
		cnt = 7;
		for(int i=1; i<8; i++){
			if(arr[i] == cnt){
				cnt--;
			}else{
				cout<<"mixed"<<endl;
				return 0;
			}
		}
		cout<<"descending"<<endl;
	}else{
		cout<<"mixed"<<endl;
	}
	return 0;
}
