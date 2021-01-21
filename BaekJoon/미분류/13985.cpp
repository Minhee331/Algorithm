#include <iostream>
using namespace std;
int main(){
	char ch[10];
	cin.getline(ch, 10);
	int a = ch[0]-48;
	int b = ch[4]-48;
	int c = ch[8]-48;
	if(a+b==c){
		cout<<"YES";
	}else cout<<"NO";
}
