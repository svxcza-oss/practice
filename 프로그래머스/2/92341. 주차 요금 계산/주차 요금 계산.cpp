#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> inTime, total;
    
    for(int i = 0; i<(int)records.size(); i++){
        stringstream ss(records[i]);
        string time, car, state;
        ss >> time >> car >> state;
        
        int t = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
        
        if(state == "IN"){
            inTime[car] = t;
            //들어갈때 차 번호랑 들어간 시간을 넣어야하고
        }
        else{
            total[car] += t - inTime[car];
            inTime.erase(car);
            //나오면 해당 차 번호에 나간 시간을 빼고
        }}
        
        for(auto& [car,t] : inTime){
            //안나간차? 그러면 24:00까지 해줘야지
            total[car] += 1439 - t;
        }
        
        vector<int> answer;
        for(auto&[car, minutes]: total){
            int fee = fees[1];
            if(minutes > fees[0]){
                int over = minutes - fees[0];
                fee += (over+fees[2]-1)/fees[2]*fees[3];
            }
            answer.push_back(fee);
        }
     
    
    return answer;
}

/*

기본시간
기본 요금
단위시간
단위 요금

시간 + 차량번호 + 나갔는지 안나갔는지

그리고 번호 순서대로? 하라는건가

그리고 24시간을 기준으로 함
*/