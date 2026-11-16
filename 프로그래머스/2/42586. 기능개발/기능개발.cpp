#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> res;
    
    for(int i = 0; i<speeds.size(); i++){
        int day = (100 - progresses[i] + speeds[i]-1 ) / speeds[i];
        answer.push_back(day);
        
    }
    
    int cnt =1;
    int base = answer[0];
    for(int i = 1; i<speeds.size(); i++){
        if(answer[i] <= base) cnt++; 
        else{
            res.push_back(cnt);
            base = answer[i];
            cnt = 1;
        }
    }
    
    res.push_back(cnt);
    return res;
}

/*
하루에 1,30,5
93,30,55

 7 -> 3 -> 9니까...
 자기 뒤에보다 작으면....
 
 
첫번째는 7일 걸리고 
두번째는 3일
세번째는 9일

아 근데 배포를 하려면 첫번째가 완료 되어야 된다?
*/