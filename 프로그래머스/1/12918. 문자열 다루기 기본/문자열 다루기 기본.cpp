#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    int len = s.length();
    int cnt = 0;
    if(len != 4 && len != 6) return false;
    
    for(char c: s) {
        if(c < '0' || c > '9')
            return false;
    }
    
    return answer;
}