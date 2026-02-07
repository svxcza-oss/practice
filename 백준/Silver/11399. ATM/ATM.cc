#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//11399

int main(){
    int n; int sum = 0; int ans = 0;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i<n; i++) cin >> v[i];
    
    sort(v.begin(),v.end());
    for(int i = 0; i<n; i++){
        sum += v[i];
        ans += sum;
    }
    
    cout << ans << endl;
    return 0;
}
