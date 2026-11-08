#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    // 차량번호랑 시간 계산해야하니까 차량 번호를 기억하고 있어야함
    map<int, int> T, charge;
    vector<int> res;
    
    for(int idx = 0; idx<records.size(); idx++){
        stringstream ss(records[idx]);
        int car_num; 
        string state, time;
        ss >> time >> car_num >> state;
        
        int t = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
        
        if(state == "IN"){
            T[car_num] = t;
        }
        else if(state == "OUT"){
            charge[car_num] += t - T[car_num] ;
            T.erase(car_num);
        }
        
    }
    
    for(auto& [car, inTime] : T){
        charge[car] += 1439 - inTime;
    }
    
    for(auto& [car, minutes] : charge){
        if(minutes > fees[0]){
            int over = minutes - fees[0];
            int units = (over + fees[2] -1) / fees[2];
            int fee = fees[1] + units*fees[3];
            res.push_back(fee);
        }
        else{
            res.push_back(fees[1]);
        }
    }
   

    
    return res;
    
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