#include <iostream>
using namespace std;

int dp[41][2] = {0,};

int main(void){
    int n;
    cin >> n;
    
    //피보나치 수열의 앞은 이미 정해져 있으니까 미리 카운트 해놓기.
    dp[0][0] = 1; dp[0][1] = 0;
    dp[1][0] = 0; dp[1][1] = 1;
    
    for(int i = 2; i<=40; i++){ //미리 세어두기
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    
    while(n--){
        int a;
        cin >> a;
    
        //원하는 숫자 거기만 출력
        cout << dp[a][0] << " " << dp[a][1] << endl;
    }
    return 0;
}
