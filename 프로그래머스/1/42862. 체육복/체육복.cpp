#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    vector<int> answer(n+1, 1);
    for(int l : lost) answer[l]--;
    for(int r : reserve) answer[r]++;
    
    for(int i = 1; i<=n; i++){
        if(answer[i] == 0){
            if(answer[i-1] == 2){
                answer[i-1]--;
                answer[i]++;
            }
            
            else if(answer[i+1] == 2){
                answer[i+1]--;
                answer[i]++;
            }
        }
    }
    
    int res = 0;
    for(int i=1; i<=n; i++) if(answer[i] >= 1) res++;
    return res;
}