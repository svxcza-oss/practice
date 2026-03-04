#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<int> arr(n);
    
    vector<int> dp(n); fill(dp.begin(),dp.end(),1);
    
    for(int i = 0; i<n; i++) cin >> arr[i];
    
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    
    return 0;
}
