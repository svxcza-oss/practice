#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int H = park.size();
    int W = park[0].size();
    
    int r = 0,  c = 0;
    
    
    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            if(park[i][j] == 'S'){
                r = i;
                c = j;
            }
        }
    }
    
    
    for(string route : routes){
        char dir = route[0];
        int dist = route[2] - '0';
        
        int drow = 0, dcolumn = 0;
        
        if(dir == 'E') dcolumn = 1;
        else if(dir == 'W') dcolumn = -1;
        else if(dir == 'S') drow = 1;
        else if(dir == 'N') drow = -1;
        
        int next_r = r;
        int next_c = c;
        
        bool possible = true;
        
        for(int step = 0; step<dist; step++){
            next_r += drow;
            next_c += dcolumn;
            
            if(next_r < 0 || next_c < 0 || next_r >= H || next_c >= W || park[next_r][next_c] == 'X'){
                possible = false;
                break;
            }
            
        }
        
        if(possible){
            r = next_r;
            c = next_c;
        }
    }
    return {r,c};
}

/*
w -> 왼쪽
e -> 오른쪽
n -> 위에
s -> 아래


그러면...... 오른쪽 두칸은 열 + 1
왼쪽은 -1
위에는 행만 -1
아래는 행만 +1
*/