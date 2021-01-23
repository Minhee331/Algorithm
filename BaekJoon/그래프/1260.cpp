#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int visited[1001]; //방문 체크
vector<int> node[1001]; // node 가 숫자 1부터 들어갈 수 있도록 1001로 생성 
 
void DFS(int x){
    if(visited[x]){ //x노드를 방문했다면,  리턴  
        return; 
    }
    visited[x] = true; //처음 방문한 노드라면 방문처리 
    printf("%d ", x);
    for(int i=0; i<node[x].size(); i++){ //x 에 인접한 node를 방문한다.  
        int y = node[x][i]; //인접 노드에 대해 dfs를 수행한다.  
        DFS(y);
    }
}
 
void BFS(int start){
    queue<int> q; //queue 선언
    q.push(start); //queue에 시작점을 넣는다. 
    visited[start] = true;//방문하면 true 
    while(!q.empty()){ //q가 empty가 아닐때까지 반복 
        int current = q.front(); //q의 맨 앞부분을 current에 저장 
        q.pop(); //pop 
        printf("%d ", current); //current를 출력 
        for(int i=0; i<node[current].size(); i++){ //current 에 인접한 node를 방문한다.  
            int next = node[current][i]; //current 와 인접한 node인 next 
            if(!visited[next]){ //방문하지 않은 노드라면 
                q.push(next); //q에 next를 넣어준다. 
                visited[next] = true; //방문처리  
            }
        }
    }
}
 
int main(){
    int n, m, v;
    scanf("%d%d%d", &n, &m, &v); //정점 개수n, 간선 개수 m, 탐색 시작할 정점 번호 v 
    for(int i=0; i<m; i++){
        int a, b; // 간선을 연결하는 두 정점 a,b;
        cin>>a>>b; 
        //각 정점을 연결해 간선을 만듦 
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i=0; i<=n; i++){ 
        //정점 번호가 작은 것을 먼저 방문해야하기 때문에 정렬한다.  
        sort(node[i].begin(), node[i].end()); 
    }
    DFS(v);
    printf("\n"); 
    //dfs 를 수행할 때 방문 체크를 했으므로, 초기화해야 한다.
    fill_n(visited, 1001, 0);
    BFS(v);
    return 0; 
} 

