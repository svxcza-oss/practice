#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    bool IsP[1000001];
    fill(IsP,IsP+1000001, true);
    IsP[0] = false;
    IsP[1] = false;
    
    for(int i = 2; i*i<=m; i++){
        if(IsP[i]){
            for(int j = i*i; j<=m; j += i){
                IsP[j] = false;
            }
        }
    }
    
    for(int i = n; i<=m; i++){
        if(IsP[i]) cout << i << "\n";
    }
    return 0;
}
