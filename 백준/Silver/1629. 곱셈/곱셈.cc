#include <iostream>
using namespace std;

typedef long long ll;

ll S(ll a, ll b, ll c){ // a = 밑 b = 몇제곱
    if(b == 0) return 1;
    if(b == 1) return a % c;
    
    ll tmp = S(a,b/2,c); //여기서 리턴값을 받음
    
    tmp = (tmp * tmp) % c;
    
    if(b %2==0) return tmp;//홀수제곱?
    else return (tmp * (a%c)) % c;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m,l;
    cin >> n >> m >> l;
    cout << S(n,m,l) << "\n";
    
    return 0;
}
