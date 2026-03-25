#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    vector<int> res(n+1,INT_MAX);
    vector<vector<pair<int,int>>> line;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    line.resize(n+1);
    while(m--){
        int from, to, weight;
        cin >> from >> to >> weight;
        
        line[from].push_back({to,weight});
    }
    
    int start, end;
    cin >> start >> end;
    
    res[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int cur_edge = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        if (res[cur_node] < cur_edge) continue;
        for(int i = 0; i<line[cur_node].size(); ++i){
            int next_node = line[cur_node][i].first;
            int next_edge = line[cur_node][i].second;
            
            if(res[next_node] > res[cur_node] + next_edge){
                res[next_node] = res[cur_node] + next_edge;
                pq.push({res[next_node], next_node});
            }
            
        }
    }
    cout << res[end];
    return 0;
}
