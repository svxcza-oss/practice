#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    int n,e,v;
    cin >> n >> e >> v;

    vector<vector<pair<int,int>>> graph(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> res(n+1, INT_MAX);
    
    res[v] = 0;
    graph.resize(n+1);
    while(e--){
        int from, to, end;
        cin >> from >> to >> end;
        
        graph[from].push_back({to,end});
    }
    
    pq.push({0,v});
    while(!pq.empty()){
        int cur_edge = pq.top().first;
        int cur_node = pq.top().second;
        
        pq.pop();
        for(int i = 0; i<graph[cur_node].size(); ++i){
            int next_node = graph[cur_node][i].first;
            int next_edge = graph[cur_node][i].second;
            
            if (res[cur_node] < cur_edge) continue;
            
            if(res[next_node] > res[cur_node] + next_edge){
                res[next_node] = res[cur_node] + next_edge;
                pq.push({res[next_node], next_node});
            }
            
        }
    }
    
    for(int i = 1; i<=n; i++){
        if(res[i] == INT_MAX) cout << "INF" << "\n";
        else cout << res[i] << "\n";
    }
    
    return 0;
}




