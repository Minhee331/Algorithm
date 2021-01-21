#include <iostream>
using namespace std;
int main(){
	char ch[101];
	int alpha[26]={0,};
	cin>>ch;
	for(int i=0; ch[i]!='\0'; i++){
		alpha[ch[i]-97]++;
	}
	for(int i=0; i<26; i++){
		cout<<alpha[i]<<" ";
	}
}
