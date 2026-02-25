#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


class S{
private:
    int n,m;
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,-1,1};
    queue<pair<int,int>> q;
    vector<vector<int>> map;
    vector<vector<int>> dist;
    
    void BFS(){
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            
            for(int i = 0; i<4; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(map[nx][ny] == 1 && dist[nx][ny] == -1){
                        dist[nx][ny] = dist[cur.first][cur.second] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    
    
public:
    void V(){
        cin >> n >> m;
     
        map.assign(n, vector<int> (m));
        dist.assign(n,vector<int>(m,-1));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> map[i][j];
                if(map[i][j] == 2){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
                
                if(map[i][j] == 0) dist[i][j] = 0;
            }
        }
        
        BFS();
     
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) cout << dist[i][j] << " ";
            cout << "\n";
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    S solve;
    solve.V();
    return 0;
}
