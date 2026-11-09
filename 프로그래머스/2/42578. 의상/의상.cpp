#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> P;
    
    for(auto& c: clothes){
        P[c[1]]++;   
    }
    for(auto& p : P){
        answer *= (p.second+1);
    }
    
 
    answer -=1;
    return answer;
}