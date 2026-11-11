#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int r = maps.size();
    int c = maps[0].size();
    
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    vector<vector<int>> dist(r, vector<int>(c, -1)); //전체 지도 
    queue<pair<int,int>> q; // 큐
    
    int start_x = 0; int start_y = 0; //시작점
    
    q.push({start_x, start_y}); //시작점 밀어 넣고
    
    while(!q.empty()){ //q가 비어있을때까지??
        auto [x,y] = q.front(); q.pop(); //이건 어디 원소를 가져와서 하는거지 아아 아니다 큐에 있는 맨 첫번째 원소 가져와서 팝시켜
        for(int d = 0; d<4; d++){ //그리고 이제 움직이는거지 4방향으로 
            int nx = x + dx[d] ,  ny = y + dy[d]; //이동할 걸음? 시작점 + 
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;   // 이 줄을 먼저

            if(nx == 0 && ny == 0 || maps[nx][ny] != 1) continue;
            maps[nx][ny] = maps[x][y] + 1;
            q.push({nx,ny});
        }
    }
    
    if(maps[r-1][c-1] == 1) return -1;
    
    
    
    return maps[r-1][c-1];
}