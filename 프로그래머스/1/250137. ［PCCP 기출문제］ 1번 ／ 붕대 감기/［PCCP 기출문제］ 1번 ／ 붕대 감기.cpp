#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int t = bandage[0];
    int s = bandage[1];
    int p = bandage[2];
   
    int cur_heal = health;
    int max_time = attacks.back()[0];
    int conti = 0;
    int idx =0;
    
    
    for(int i = 1; i<= max_time; i++){
        if(i == attacks[idx][0]){
            cur_heal -= attacks[idx][1];
            conti = 0;
            idx++;
            if(cur_heal <= 0) return -1;
        }
        else{
            cur_heal += s;
            conti++;
            if(conti == t) {
                cur_heal += p;
                conti = 0;
            }
            if(cur_heal > health) cur_heal = health;
        }
    }
    return cur_heal;
    
}

/*

이번 초에 공격이 있나?
├─ 있음 → 체력 -= 피해, 연속 = 0, 체력 <= 0이면 -1 반환
└─ 없음 → 체력 += s, 연속++
          연속 == t면 체력 += p, 연속 = 0
          체력을 최대 체력으로 자르기
          
          
이걸 그 공식에 대입을 해보면....일단 구현하라는데로 하면 되고 과거의 기록은 굳이? 그냥 계속 이끌면 되는거니까ㅣ
*/