#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    const int inf = 1e9;
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> dp(n+1,vector<int> (n+1,inf));
    
    for(int i = 1; i<=n; i++) dp[i][i] = 0;
    
    for(int i = 0; i<m; i++){
        int u,v,w;
        cin >> u >> v>> w;
        
        if(w < dp[u][v]) dp[u][v] = w;
    }
    
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            if(dp[i][k] == inf) continue;
            for(int j =1 ; j<=n; j++){
                if(dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k]+dp[k][j];
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(dp[i][j] == inf) cout << 0 << " "; // 최대경우의 수
            else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
