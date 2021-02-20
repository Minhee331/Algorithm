#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const pair<long long, int> &v1, const pair<long long, int> &v2){
	if(v1.second == v2.second){
		return v1.first < v2.first;
	}
	return v1.second > v2.second;
}
int main(){
    int n; // 준규가 가지고 있는 숫자 카드의 개수 : n
    long long number;
    cin>>n;// n 입력  
    map<long long, int> m; // key: 숫자 카드에 적혀있는 정수, value: 정수의 개수 
	vector<pair<long long, int> > v; // map 을 정렬하기위해 vector 선언  
	for(int i=0; i<n; i++){
		 cin>>number; //숫자 카드에 적혀있는 정수 입력  
		 m[number]++; //해당 정수를 key로 가진 value ++ 
	}
	copy(m.begin(), m.end(), back_inserter(v)); //입력받은 map을 vector로 복사  
	sort(v.begin(), v.end(), cmp); //정렬 
	cout<<v[0].first; //정렬된 vector값중 첫번째 값을 출력 
}
