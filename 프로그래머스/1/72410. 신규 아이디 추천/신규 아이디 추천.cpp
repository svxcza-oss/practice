#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i = 0; i<new_id.length(); i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] += 32; 
    }
        
    for(int i = 0; i<new_id.length(); i++){
        char c = new_id[i];
        if((c >= 'a' && c <= 'z') || c == '-' || c == '_' || c == '.' || (c >= '0' && c <= '9'))
            answer += c;
    }
    
    string temp = "";
    for(int i = 0; i<answer.length(); i++){
        if(answer[i] == '.'){
            temp += answer[i];
            while(i+1 < answer.length() && answer[i+1] == '.') i++; 
        }
        else{
            temp += answer[i];// 남아있던거 temp에 넣어주기
        }
    }
    answer = temp;
        
    if(!answer.empty() && answer.front() == '.') answer.erase(answer.begin());
    
    if(!answer.empty() && answer.back() == '.') answer.erase(answer.end()-1);
    
    if(answer.empty()) answer = "a";
        
    if(answer.length() > 15) answer = answer.substr(0,15);
    if(!answer.empty() && answer.back() == '.') answer.erase(answer.end()-1);
    
    while (answer.length() < 3) answer += answer.back();
    
    
    
    return answer;
}
        
        
    
   


/*
1. 소문자 
2. 문자
3. .연속
4. . 처음
5. 빈 문자열 삭제
6. 15
7. 2
3 <= len <= 15
알파벳 소문자, 숫자, -, _, .

.은 처음과 끝, 연속 안됌
*/