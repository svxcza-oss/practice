#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int input_arr[1000001];
    cin >> n;
    
    for(int i = 0; i<n; i++) cin >> input_arr[i];
   
    vector<int> v(input_arr, input_arr+n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end()); //중복제거
    
    for(int i = 0; i<n; i++){
        int x = input_arr[i];
        auto it = lower_bound(v.begin(), v.end(), x);
        cout << (it - v.begin()) << " ";
    }
    return 0;
    
}
