#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];

struct edge{ //u, v, c로 구성된 edge 
	int u,v,w;
	edge(int u, int v, int w){
		this->u = u; //정점 
		this->v = v; //정점 
		this->w = w; //가중치 
	}
};

int find(int u){ //루트를 찾는다.  
	if(u == parent[u]){ //자신의 부모가 정점 자신이면  
		return u; //자신이 루트이므로 리턴  
	}
	return parent[u] = find(parent[u]); //루트를 계속 찾는다.  
}

void merge(int u, int v){ //집합을 합친다.  
	u = find(u); //정점 u가 속한 루트를 찾는다.  
	v = find(v); //정점 v가 속한 루트를 찾는다.  
	parent[v] = u; //합친다.  
}
int compare_comp(const edge &a, const edge &b){ //sort 초건  
	return a.w < b.w; //가중치를 기준으로 한다.  
}

int kruskal(vector<edge> &edges){ //크루스칼 함수  
	int cost = 0; //비용 초기화 
	sort(edges.begin(), edges.end(), compare_comp); //가중치를 기준으로 오름차순 정렬  
	for(int i=0; i<edges.size(); i++){ 
		if(find(edges[i].u)==find(edges[i].v)){ //사이클 여부를 확인한다.  
			continue;
		}
		merge(edges[i].u, edges[i].v); //두 집합을 하나로 합친다.  
		cost += edges[i].w;
	}
	return cost;
}
int main(){
	int v,e; //정점의 개수 v, 간선의 개수 e 
	cin>>v>>e; //입력
	vector<edge> edges; 
	for(int i=1; i<=v; i++){
		parent[i] = i;
	}
	for(int i=0; i<e; i++){ //edge를 입력받는다.  
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back(edge(a,b,c)); //edge에 넣는다.  
		edges.push_back(edge(b,a,c));
	}
	cout<<kruskal(edges);//비용을 출력한다.  
	return 0;
}

