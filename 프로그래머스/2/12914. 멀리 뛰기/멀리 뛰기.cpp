#include <bits/stdc++.h>
using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> dp(n+1, 1);
    dp[0] = 1; dp[1] = 1;
   
    
    for(int i =2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1234567;
    }
    answer = dp[n];
    
    return answer;
}

/*
dp? greedy?? 음 모든 경우의 수니까... combination구현기.?
*/