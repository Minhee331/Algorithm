#include<iostream>
using namespace std;
//5354
int main(){
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		for(int j = 0; j<arr[i]; j++){
			if(j==0 || j == arr[i]-1){
				for(int k=0; k<arr[i]; k++){
					cout<<"#";
				}
			}else{
				cout<<"#";
				for(int k=0; k<arr[i]-2; k++){
					cout<<"J";
				}
				cout<<"#";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}
