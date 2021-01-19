#include <iostream>
using namespace std;
int main(){
	char ch[5];
	int n, sum, len;
	while(1){
		sum=0;
		cin>>ch;
		if(ch[0]=='0'){
			break;
		}
		for(len=0; ch[len]!='\0'; len++){
			n = ch[len]-48;
			if(n==1){
				sum+=2;
			}else if(n==0){
				sum+=4;
			}else{
				sum+=3;
			}
		}
		cout<<sum+len+1<<'\n';
	}	
}
