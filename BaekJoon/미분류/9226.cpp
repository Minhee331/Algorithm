#include <iostream>
using namespace std;
int main(){
	char new_s[23];
	char s[21];
	int cnt, i, len, j;
	while(1){
		cin>>s;
		cnt = 0;
		if(s[0]=='#'){
			break;
		}
		for(len=0; s[len]!='\0'; len++){}
		for(i=0; s[i]!='\0'; i++){
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
				break;
			}
		}
		for(j =i; s[j]!='\0'; j++){
			new_s[cnt] = s[j];
			cnt++;
		}
		for(j =0; j!=i; j++){
			new_s[cnt] = s[j];
			cnt++;
		}
		new_s[cnt] = 'a';
		new_s[++cnt] = 'y';
		new_s[++cnt] = '\0';
		cout<<new_s<<'\n';
	}
	return 0;
}
