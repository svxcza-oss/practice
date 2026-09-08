#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    int res;
    
    if(len % 2 != 0){
        res = len / 2; // 홀수 일때
        answer += s[res];
    } 
    else {
        res = len / 2 -1; // 짝수 일때
        answer += s[res];
        answer += s[res+1];
    }
    return answer;
    
}

int main(){
    
}