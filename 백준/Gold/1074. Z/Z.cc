#include <iostream>
#define sqr flag * flag
using namespace std;

int main(){
    int n,r,c;
    cin >> n >> r >> c;
    int res = 0;
    
    while(n>0){
        int flag = 1 << (n-1);
        if(flag > r && flag > c) {// 1사분면
            n--;
        }
        else if(flag > r && flag <= c){
            res += sqr;
            c -= flag;
            n--;
        } //2사분면
        else if(flag <= r && flag >c){
            res += 2*sqr;
            r -= flag;
            n--;
        } //3사분명
        else {
            res += 3*sqr;
            c -= flag;
            r -= flag;
            n--;
        } //4사분면
    }
    cout << res << endl;
}
