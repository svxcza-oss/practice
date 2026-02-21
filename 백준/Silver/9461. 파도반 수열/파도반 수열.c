#include <stdio.h>
#define ll long long

int main(){
    ll res[101] = {0,1,1,1,2,2,3,4,5,7,9,12};
    int n;
    scanf("%d", &n);
    
    for(int i = 12; i<=100; i++) res[i] = res[i-2] + res[i-3];
    
    while(n--) {
        int m;
        scanf("%d", &m);
        printf("%lld\n", res[m]);
    }
}
