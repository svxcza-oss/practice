#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
   
    
    int n = land.size();
    int m = land[0].size();
    
    vector<vector<bool>> visited(n, vector<bool> (m,false));
    vector<int> colsum(m,0);

    
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    
    queue<pair<int,int>> q;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            
            if(land[i][j] == 0 || visited[i][j]) continue; 
            q.push({i,j});
            visited[i][j] = true;
            set<int> cols;
             int cnt = 0;
          

             while(!q.empty()){
            auto [x,y] = q.front();q.pop();
                 cnt++;            // 여기
                cols.insert(y);

             for(int d = 0; d<4; d++){
            int nx = x + dx[d]; int ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
                 if (land[nx][ny] == 0 || visited[nx][ny]) continue;
                             visited[nx][ny] = true;
                 

            q.push({nx,ny});
                
        }
    } 
            for(int c : cols) colsum[c] += cnt;
        }
    }
    
    return *max_element(colsum.begin(), colsum.end());
}

/*

음 일단 이건 사이즈만큼 반복됨,
그리고 1이 석유가 있는곳.
그러면 1이 있는 시점부터 1만 타고가면 됨
반복구간은 사이즈만큼 돌기

흠? 그러면 어떻게 해야하지
*/