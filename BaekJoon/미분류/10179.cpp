#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	double *arr = new double[n];
	for(int i=0; i<n; i++){
		cin>>arr[i]; 
	}
	cout.precision(2);
	cout<<fixed;
	for(int i=0; i<n; i++){
		cout<<"$"<<arr[i]*0.8<<"\n"; 
	}
}
