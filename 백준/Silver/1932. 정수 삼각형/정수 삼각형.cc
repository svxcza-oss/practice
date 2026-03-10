#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<int>> dp = matrix;
    for(int i = n-2; i>=0; i--){
        for(int j = 0; j<=i; j++){
            dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    
    cout << dp[0][0] << "\n";
    return 0;
}
