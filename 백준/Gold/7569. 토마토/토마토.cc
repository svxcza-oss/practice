//토마토 3차원

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct pos{
    int z,y,x;
};

queue<pos> Q;

int map[101][101][101];
int dx[6] = {0,0,0,0,-1,1};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0, 1,-1,0,0}; //왜 -1이 먼저인가? 좌표 그려서 분석해보기 딱히 상관없는 이유

void BFS(int h, int n, int m){
    while(!Q.empty()){
        pos cur = Q.front();
        Q.pop();
        
        int cy = cur.y;
        int cx = cur.x;
        int cz = cur.z;//구조체로 그거 점 해서 좌표
        
        for(int i = 0; i<6; i++){
            int nz = cz + dz[i];
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if(ny<0 || nx<0 || nz<0 || nz>=h || ny>=n || nx >= m) continue;//h의 출처는 어디..?
            
            if(map[nz][ny][nx] == 0){ //여기서 어떤 부분이 헷갈렸는가. x->y 기존의 순서에서 z->y->x
                map[nz][ny][nx] = map[cur.z][cur.y][cur.x] + 1;
                Q.push({nz,ny,nx});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,h;
    cin >> m >> n >> h;
    
    for(int i = 0; i<h; i++){
        for(int j  =0; j<n; j++){
            for(int z = 0; z<m; z++){
                cin >> map[i][j][z];
                if(map[i][j][z] == 1) Q.push({i,j,z});
            }
        }
    }
    BFS(h,n,m);
    
    int res = 0;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int z = 0; z<m; z++){
                if(map[i][j][z] == 0){
                    cout << -1;
                    return 0;
                }
                res = max(res,map[i][j][z]); //왜 높이가 맨 앞으로 오는가
            }
        }
    }
    if (res == 1) cout << 0; // 처음부터 다 익어있던 경우
    else cout << res - 1 << endl;
    
    return 0;
    
}
