#include <stdio.h>
#include <string.h>
//1012

int n,m,k;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int map[50][50] = {0,};
int visited[50][50] = {0,};

void DFS(int y, int x){
    visited[y][x] = 1;
    
    for(int i = 0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny >= 0 && nx >=0 && ny < n && nx < m){
            if(map[ny][nx] == 1 && !visited[ny][nx]) DFS(ny,nx);
        }
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d", &m,&n,&k);
        
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        
        for(int i = 0; i<k; i++){
            int x,y;
            scanf("%d %d", &x,&y);
            
            map[y][x] = 1;
        }
    
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                cnt++;
                DFS(i,j);
            }
        }
    }
    
    printf("%d\n", cnt);
 }
return 0;
}

