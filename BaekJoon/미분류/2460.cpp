#include<iostream>
using namespace std;
int main(){
	int current = 0, person, max=0;
	for(int i=0; i<10; i++){
		cin>>person;
		current-=person;
		if(current>max){
			max = current;
		}
		cin>>person;
		current+=person;
		if(current>max){
			max = current;
		}
	}
	cout<<max;
}
