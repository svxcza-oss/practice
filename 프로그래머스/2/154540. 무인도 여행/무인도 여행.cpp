#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> board;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool visited[100][100];


int dfs(int x, int y){
    visited[x][y] = true;
    int sum = board[x][y] - '0';
    for(int d =0; d<4; d++){
        int nx = x+dx[d];
        int ny = y + dy[d];
        if(nx < 0 || ny < 0|| nx >=n || ny >=m)continue;
        if(board[nx][ny] == 'X' || visited[nx][ny] == true) continue;
        sum += dfs(nx,ny);
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    board = maps;
    
    n = maps.size();
    m = maps[0].size();
    
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++)
            if(!visited[i][j] &&  board[i][j] != 'X') answer.push_back(dfs(i,j));
    }
    
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    
    return answer;
    
}

/*
이것도 약간 석유시추 느낌인데? 
여기까지 밖에 기억을 못하겠어
*/