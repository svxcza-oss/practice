#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt  = 0;

    int tmp = 0;
    int res_cnt = 0;
    
    while(s != "1"){
        for(int c : s){
        if(c == '0') cnt++;
        } 
    
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
    
        int len = s.size();
        string bin = "";
        while(len > 0){
            
            bin += to_string(len%2);
            len/=2;
             
        }
        reverse(bin.begin(), bin.end());
        s = bin;
        res_cnt++;
     }
    
    answer.push_back(res_cnt);
    answer.push_back(cnt);
    
    return answer;
}

/*

x의 모든 0을 제거.
x의 길이를 c
c를 2진법으로 표현한 문자열

0111010 
1111 --> 길이: 4
100

아 그니까 이걸 0이 없어질때까지 계속하고
바꾼 횟수, 0뻰 횟수

*/