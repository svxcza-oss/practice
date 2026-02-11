#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int,int>> Q; 

int map[1001][1001];
int dx[4] = {0,0,-1,1}; //2차원 bfs를 위한것..
int dy[4] = {1,-1,0,0};

void BFS(int m, int n){
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        
        int cy = cur.first;
        int cx = cur.second;
        
        for(int i = 0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if(ny<0 || nx<0 || ny>=n || nx >= m) continue;
            
            if(map[ny][nx] == 0){
                map[ny][nx] = map[cy][cx] + 1;
                Q.push({ny,nx});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> m >> n;
    
    for(int i = 0; i<n; i++){
        for(int j  =0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) Q.push({i,j});
        }
    }
    BFS(m,n);
    
    int res = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 0){
                cout << -1;
                return 0;
            }
            if(res < map[i][j]) res = map[i][j];
        }
    }
    cout << res-1 << endl;
    return 0;
    
}
