#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int res = 0;
    int sum = 0;
    int temp = x;
    
    while(temp > 0){
        sum += temp % 10; // 1의 자리수 커팅
        temp /= 10; // 오른쪽으로 비트 시프트 느낌
    }
    
    if(x % sum == 0) answer = true;
    else answer = false;
    
    return answer;
}

/*

그니까 10이면 2자리수로 x가 나누어져야 한다?

*/