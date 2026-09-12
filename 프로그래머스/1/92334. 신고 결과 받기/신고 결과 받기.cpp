/*
 id_list    report    k    result
 ["muzi", "frodo", "apeach", "neo"]
 
 ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
 2
 
 [2,1,1,0] --> 무지는 2번 신고 했는데 둘다 정지해서 2, 프로도는 한번 신고했는데 그친구도 정지엔딩
 어피치도
 ["con", "ryan"]    ["ryan con", "ryan con", "ryan con", "ryan con"]    3    [0,0]
 */


#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_map<string, vector<string>> history;
    unordered_map<string, int> report_cnt;
    //일단 누가 누구를 신고했는지 기록.
    
    unordered_set<string> unique_report(report.begin(), report.end());
    
    for(const string& a : unique_report){
        stringstream ss (a);
        string from, to;
        ss >> from >> to;
        
        history[from].push_back(to);
        report_cnt[to]++;
    }
    
    for(int i = 0; i<id_list.size(); i++){
        string user = id_list[i]; //해당 이름이 저장됨
        
        for(const auto& target : history[user]){ //해당이름에 저장된 vector<string>을 target으로 받아옴
            if(report_cnt[target] >= k) answer[i]++;
            
        }
    }
    return answer;
}
