#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    int n;
    cin >> n;

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0; i<n; i++){
        int t;
        cin >> t;
        pq.push(t);
    }
    
    vector<int> res(n+2);
    for(int i = 1; i<n; i++){
        int a = pq.top();
        pq.pop();
        
        if(pq.empty()){
            cout << "0" << "\n";
            break;
        }
        
        int b = pq.top();
        pq.pop();

        res[i+1] = (a+b) + res[i];
        pq.push(a+b);
    }
    
    cout << res[n] << "\n";
    return 0;
}
