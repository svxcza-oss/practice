#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> max_heap;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        
        if(x == 0){
            if(max_heap.empty()) cout << "0\n";
            else{
                int val = max_heap.top().second;
                cout << val << "\n";
                max_heap.pop();
            }
        }
        else{
            max_heap.push({abs(x),x});
        }
        
    }
    return 0;
}
