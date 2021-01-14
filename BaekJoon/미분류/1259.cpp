#include <iostream>
using namespace std;
int main(){
	int len, i, flag;
	char ch[6];
	while(1){
		flag = 0;
		if(ch[0]=='0'){
			break;
		}
		cin>>ch;
		for(len=0; ch[len]!='\0'; len++){}
		for(i=0; i<len/2; i++){
			if(ch[i]!=ch[len-i-1]){
				flag = 1;
				cout<<"no"<<endl;
				break;
			}
		}
		if(flag == 0 && ch[0]!='0'){
			cout<<"yes"<<endl;	
		}
	}
	return 0;
}
