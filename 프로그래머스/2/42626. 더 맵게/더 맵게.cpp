#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int tmp;
    
    while(pq.top() < K && pq.size() >= 2){
        
            int first = pq.top();
            pq.pop();
            
            tmp = first + (pq.top() * 2);
            pq.pop();
            pq.push(tmp);
            
            answer++;
    }
    if(pq.top() < K) return -1;
    
    return answer;
}

/*
가장 작은 거 + 두번째 작은거 * 2

1,2,3,9,10,12
7

1) 1+2*2 = 5

2) 3 + 5*2 = 13
전체가 완성됐으니까 리턴2?
*/