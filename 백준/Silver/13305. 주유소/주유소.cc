#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<ll> street;
    vector<ll> OilB;
    
    ll res = 0;
    for(int i = 0; i<n-1; i++) {
        int t;
        cin >> t;
        street.push_back(t);
    }
    for(int i = 0; i<n; i++) {
        int r;
        cin >> r;
        OilB.push_back(r);
    }
    
    ll max = OilB[0];
    for(int i = 0; i<n-1; i++){
        if(OilB[i] < max) max = OilB[i];
        res += max * street[i];
    }
        
    cout << res<< "\n";
    
    
    return 0;
}
