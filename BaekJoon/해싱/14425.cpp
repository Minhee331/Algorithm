#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int n, m, cnt=0; //문자열의 개수 n과 m, 개수를 구하기 위한 cnt 
	map<string, string> mp;//문자열을 담을 map 선언  
	string str; 
	cin>>n>>m; //n, m 입력 
	for(int i=0; i<n; i++){
		cin>>str;
		mp.insert({str, str}); //map에 string 집어넣기  
	}
	for(int i=0; i<m; i++){
		cin>>str;
		if(mp.find(str) != mp.end()){ //map에서 해당 string이 있는지 찾는다.  
			cnt++; //있으면 cnt++ 
		}
	}
	cout<<cnt; //개수 출력 
}
