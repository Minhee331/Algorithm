#include <iostream>
using namespace std;
int main(){
	char ch[101];
	char ch_s[51];
	int cnt=0;
	cin>>ch;
	ch_s[cnt] = ch[0];
	cnt++;
	for(int i=1; ch[i]!='\0'; i++){
		if(ch[i]=='-'){
			ch_s[cnt] = ch[i+1];
			cnt++;
		}
	}
	ch_s[cnt] = '\0';
	cout<<ch_s;
}
