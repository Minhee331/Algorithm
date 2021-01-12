#include <iostream>
using namespace std;
int main(){
	int month, day;
	cin>>month>>day;
	if(month<2||(month==2&&day<18)){
		cout<<"Before";
	}else if(month>2||(month==2&&day>18)){
		cout<<"After";
	}else{
		cout<<"Special";
	}
	return 0;
}
