#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    queue<int> Q;
    int dist[100001];
    
    fill(dist,dist+100001, -1);
    Q.push(n);
    dist[n] = 0;
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        if(cur == m){
            cout << dist[m];
            return 0;
        }
        int next[3] = {cur-1, cur+1, cur*2};
        for(int next_m : next){
            if(next_m < 0 || next_m > 100000) continue;
            if(dist[next_m] != -1) continue;
            dist[next_m] = dist[cur] + 1;
            Q.push(next_m);
        }
    }
    return 0;
}
