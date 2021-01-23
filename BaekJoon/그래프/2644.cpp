#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int p1, p2;
int depth[101] ={0,}; //깊이 
vector<int> node[101]; // node 가 숫자 1부터 들어갈 수 있도록 8로 생성 
 
void BFS(int start){
    queue<int> q; //queue 선언
    q.push(start); //queue에 시작점을 넣는다. 
    while(!q.empty()){ //q가 empty가 아닐때까지 반복 
        int current = q.front(); //q의 맨 앞부분을 current에 저장 
        q.pop(); //pop 
        for(int i=0; i<node[current].size(); i++){ //current 에 인접한 node를 방문한다.  
            int next = node[current][i]; //current 와 인접한 node인 next 
            if(!depth[next]){ //방문하지 않은 노드라면 
                q.push(next); //q에 next를 넣어준다. 
                depth[next] = depth[current]+1; //깊이 저장 
            }
        }
    }
}
 
int main(){
    int n, m; //전체 사람의 수 
    scanf("%d%d%d%d", &n, &p1, &p2, &m); //전체 사람의 수 n, 촌수 계산 해야하는 사람 p1, 촌 수 계산해야하는 다른 사람 p2 
    for(int i=0; i<m; i++){
        int x, y; // 간선을 연결하는 두 정점 x,y(부모자식간의 관계를 나타냄);
        cin>>x>>y; 
        //각 정점을 연결해 간선을 만듦 
        node[x].push_back(y);
        node[y].push_back(x);
    }
    BFS(p1);
    if(depth[p2]==0){
        printf("-1"); //깊이가 0이면 p2를 방문하지 못했다는 것이므로 -1출력 
    }else{
        printf("%d", depth[p2]); //깊이(촌수)를 출력한다. 
    }
    return 0; 
} 
