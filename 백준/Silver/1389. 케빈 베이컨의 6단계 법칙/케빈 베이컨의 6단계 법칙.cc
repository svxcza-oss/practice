#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[101];
int dist[101];



void BFS(int start){
    queue<int> Q;
    Q.push(start);
    dist[start] = 0;
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        for(int i = 0; i<graph[cur].size(); i++){
            int next = graph[cur][i];
            
            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                Q.push(next);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i<m; i++){
        int x,y;
        cin >> x >> y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
        
    }
    int min = 999999;
    int res = 0;

    for(int i = 1; i <= n; i++){
        fill(dist,dist+101,-1);
            
        BFS(i);
            
        int sum = 0;
        for(int j = 1; j<=n; j++) sum += dist[j];
        
        if(sum < min){
            min = sum;
            res = i;
        }
    }
        
    cout << res << endl;
    return 0;
}
