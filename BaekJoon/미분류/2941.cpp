#include <iostream>
using namespace std;
//2941¹ø  
int main(){
	char ch[101];
	int i, cnt=0;
	cin>>ch;
	for(i=0; ch[i]!='\0'; i++){
		if(ch[i]=='c'&&ch[i+1]=='='){
			cnt++;
			i++;
		}else if(ch[i]=='c'&&ch[i+1]=='-'){
			cnt++;
			i++;
		}else if(ch[i]=='d'&&ch[i+1]=='z'&&ch[i+2]=='='){
			cnt++;
			i+=2;
		}else if(ch[i]=='d'&&ch[i+1]=='-'){
			cnt++;
			i++;
		}else if(ch[i]=='l'&&ch[i+1]=='j'){
			cnt++;
			i++;
		}else if(ch[i]=='n'&&ch[i+1]=='j'){
			cnt++;
			i++;
		}else if(ch[i]=='s'&&ch[i+1]=='='){
			cnt++;
			i++;
		}else if(ch[i]=='z'&&ch[i+1]=='='){
			cnt++;
			i++;
		}else{
			cnt++;
		}
	}
	cout<<cnt;
}
