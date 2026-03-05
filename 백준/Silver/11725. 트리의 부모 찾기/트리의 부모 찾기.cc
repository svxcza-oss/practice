#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void PARENT(int cur,vector<vector<int>> &tree, vector<int> &parent){
    for(int next : tree[cur]){
        if(parent[next] == 0){
            parent[next] = cur;
            PARENT(next,tree,parent);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> tree(n+1); //malloc해서 여러개 달아놓는거임
    vector<int> parent(n+1,0); //다시 저장할 벡터
    
    for(int i = 1; i<n; i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    parent[1] = -1;
    PARENT(1,tree,parent);
    
    for(int i = 2; i<=n; i++) cout << parent[i] << "\n";
    return 0;
}
