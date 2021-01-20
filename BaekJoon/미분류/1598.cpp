#include <iostream>
using namespace std;
int main(){
	int a,b,_a,_b;
	cin>>a>>b;
	int sum = 0;
	_a = a%4;
	_b = b%4;
	if(_a==0) _a+=4;
	if(_b==0) _b+=4;
	_a > _b ? sum += _a - _b :sum += _b - _a;
	if(a%4>0){
		a /= 4;
		a++;
	}else a /= 4;
	if(b%4>0){
		b /= 4;
		b++;
	}else b /= 4;
	a>b ? sum+=a-b : sum+=b-a;
	cout<<sum;
}
