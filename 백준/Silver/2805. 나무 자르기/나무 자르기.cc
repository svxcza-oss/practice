#include <iostream>
#define ll long long
using namespace std;
//파라메트릭 서치

int n,m,tree[1000001];

bool T(int mid){
    ll ans = 0;
    for(int i = 0; i<n; i++){
        if(tree[i] > mid) ans += (tree[i] - mid);
    }
    return ans >= m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >>m;
    int low = 0; int high = 0;
    for(int i = 0; i<n; i++) {
        cin >> tree[i];
        if(tree[i] > high) high = tree[i];
    }
    high ++;
    
    while(low + 1 < high){
        int mid = (high+low)/2;
        if(T(mid)) low = mid;
        else high = mid;
    }
    cout << low << "\n";
}
