#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> prev(3);
    vector<int> cur(3);
    cin >> prev[0] >> prev[1] >> prev[2];
    
    for(int i =1 ; i<n; i++){
        int r,g,b;
        cin >> r >> g >> b;
        
        cur[0] = min(prev[1], prev[2]) + r;
        cur[1] = min(prev[0], prev[2]) + g;
        cur[2] = min(prev[0], prev[1]) + b;
        
        prev = cur;
    }
    
    cout << *min_element(prev.begin(), prev.end()) << "\n";
    return 0;
}
