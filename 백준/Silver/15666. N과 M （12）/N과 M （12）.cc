#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class S{
private:
    int n,m;
    vector<int> arr;
    vector<int> res;
    
    void DFS(int dpt, int start){
        if(dpt == m){
            for(int i = 0; i<m; i++) cout << res[i] << " ";
            cout << "\n";
            return;
        }
        
        int prev = -1;
        for(int i = start; i<n; i++){
            if(arr[i] != prev){
                res[dpt] = arr[i];
                prev = arr[i];
                DFS(dpt+1, i);
            }
        }
    }
    
public:
    void V(){
        cin >> n >> m;
        arr.resize(n);
        res.resize(m);
        
        for(int i = 0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        DFS(0,0);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    S solve;
    solve.V();
    return 0;
}

