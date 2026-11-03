#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int cur_health = health;
    int max_health = health;
    
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    
    int attack_idx = 0;//현재 처리할 몬스터 공격 인덱스??
    int succ = 0; // 연속 성공 시간
    int last_attack_time = attacks.back()[0]; // 아 이러면 바로 뒤에 접근이 가능하구나..!!!! 
    

    
    for(int i = 1; i<=last_attack_time; i++){
        if(attack_idx < attacks.size() && attacks[attack_idx][0] == i ){
            cur_health -= attacks[attack_idx][1];
            succ = 0;
            attack_idx++;
            
            if(cur_health <= 0) return -1;
            
        } 
        else {
            cur_health += x;
            succ++;
        
            if(succ == t) {
                cur_health += y;
                succ = 0;
            }
            
            if(cur_health > max_health) cur_health = max_health;
        }
        
        
    }
    
    return cur_health;
}