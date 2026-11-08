#include <bits/stdc++.h>

using namespace std;

int trans_min(string s){
    return stoi(s.substr(0,2))* 60 + stoi(s.substr(3,2));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int v_l = trans_min(video_len);
    int cur_pos = trans_min(pos);
    int start = trans_min(op_start);
    int end = trans_min(op_end);
    
    for(int i = 0; i<commands.size(); i++){
        if(cur_pos <= end && cur_pos >= start) cur_pos = end;

        if(commands[i] == "next") {
            cur_pos += 10;
            if(cur_pos >= v_l) cur_pos = v_l;
        }
        else if(commands[i] == "prev"){
            cur_pos -= 10;
            if(cur_pos < 0) cur_pos = 0;
        } 
        
    }
            if(cur_pos <= end && cur_pos >= start) cur_pos = end;

    
    int h = cur_pos / 60;
    int m = cur_pos % 60;
    
    string ss = (h < 10 ? "0" : "") + to_string(h);
    string mm = (m < 10 ? "0" : "") + to_string(m);
    
    return ss + ":" + mm;
}