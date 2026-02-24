#include <iostream>
#include <algorithm>
using namespace std;

struct TIME{
    int start;
    int end;
};

bool cmp(const TIME &a, const TIME &b){
    if(a.end != b.end) return a.end < b.end;
    return a.start < b.start;
}

int main(){
    int n;
    cin >> n;
    vector<TIME> arr(n);
    
    for(int i = 0; i<n; i++) cin >> arr[i].start >> arr[i].end;
    sort(arr.begin(), arr.begin()+n, cmp);
    
    int last_t = 0; int cnt = 0;
    for(int i = 0; i<n; i++){
        if(last_t <= arr[i].start){
            cnt++;
            last_t = arr[i].end;
        }
    }
    
    cout << cnt << "\n";
    return 0;
}
