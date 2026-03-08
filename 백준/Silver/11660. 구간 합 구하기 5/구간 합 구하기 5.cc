#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> matrix(n+1,vector<int>(n+1,0));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) cin >> matrix[i][j];
    }
    
    vector<vector<int>> dp = matrix;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + matrix[i][j];
    }
    
    while(m--){
        int c,r,c1,r1;
        cin >> c >> r >> c1 >> r1;
        cout << dp[c1][r1] - dp[c-1][r1] - dp[c1][r-1] + dp[c-1][r-1] << "\n";
    }
    
    
    return 0;
}
