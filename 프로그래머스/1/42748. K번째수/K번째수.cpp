#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int idx = 0; idx < commands.size(); idx++){
        int i = commands[idx][0];
        int j = commands[idx][1];
        int k = commands[idx][2];
        
        vector<int> tmp (array.begin() + (i-1), array.begin() + j);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k-1]);
    }
    
    
    return answer;
}