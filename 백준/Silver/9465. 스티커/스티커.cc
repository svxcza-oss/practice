#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<int> prev;
    vector<int> cur;
    
    
    while(n--){
        int m;
        cin >> m;
        
        vector<int> prev(m+1), cur(m+1);
        vector<vector<int>> dp(2, vector<int>(m+1,0));

        for(int i = 1; i<=m; i++) cin >> prev[i];
        for(int i = 1; i<=m; i++) cin >> cur[i];
        
        dp[0][1] = prev[1];
        dp[1][1] = cur[1];
        
        for(int i = 2; i<=m; i++){
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + prev[i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + cur[i];
        }
        
        
        cout << max(dp[0][m], dp[1][m]) << "\n";
        
    }
    
    
    return 0;
}
