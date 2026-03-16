#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
   
    vector<int> dp(m+1,0);
    
    for(int i = 0; i<n; i++){
        int v,w;
        cin >> v >> w;
        
        for(int j = m; j>=v; j--) dp[j] = max(dp[j-v] + w, dp[j]);
    }
    
    cout << dp[m] << "\n";
    return 0;
}
