#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	while(sscanf("%d%d%d", &a, &b, &c) == 3){
		if(c-b > b-a){
			printf("%d\n", c-b-1);
		}else{
			printf("%d\n", b-a-1);
		}
	}
}
