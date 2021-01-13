#include <iostream>
using namespace std;
int main(){
	int num;
	cin>>num;
	if(num<=99){
		cout<<num/10+num%10; 
	}else if(num<=999){
		if(num%10==0){
			cout<<num/100+num%100;
		}else{
			cout<<num/10+num%10;
		}
	}
	else{
		cout<<20;
	}
}
