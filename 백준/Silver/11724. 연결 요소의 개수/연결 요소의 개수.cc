#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001]; // ==NODE * graph[1001]
bool visited[1001]; // bool배열. 0 or 1 반환.

void DFS(int x){
    visited[x] = true; //방문한곳 true(==1)
    
    for(int i = 0; i<graph[x].size(); i++){ //현 인덱스 사이즈까지
        int next = graph[x][i]; //x동 i호. c에서는 연결하고 끊어주고 다시 이어줘야했는데 그냥 주소만 알면 바로 넣어줌
        if(!visited[next]) DFS(next); //다음음을 가르키는 곳이 0(false, 즉 비어잇으면) 다시 집어넣기
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); //printf,scanf XX
    
    int n,m; int cnt = 0;
    cin >> n >> m;
    
    for(int i = 0; i<m; i++){
        int u,v;
        cin >> u >> v;
        
        graph[u].push_back(v); //new 동적할당
        graph[v].push_back(u);
    }
    
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << "\n";
}
