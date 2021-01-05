#include<iostream>
using namespace std;
//4766
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double previous, current = 0;
	cin>>previous;
	while(1){
		cin>>current;
		if(current==999){
			break;
		}
		cout.precision(2);
		cout<<fixed;
		cout<<current - previous<<"\n";
		previous = current;
	}
}
