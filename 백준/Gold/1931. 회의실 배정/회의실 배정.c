#include <stdio.h>
#define ll long long

typedef struct TIME_M{
    ll start;
    ll end;
}time;

ll cmp(const void *a, const void *b){
    time *t1 = (time*) a;
    time *t2 = (time*) b;
    
    if(t1 -> end != t2 -> end) return t1->end - t2->end;
    return t1->start - t2->start;
}

int main(void){
    ll n;
    scanf("%lld", &n);
    
    time arr[100001];
    for(ll i = 0; i<n; i++) scanf("%lld %lld", &arr[i].start, &arr[i].end);
    
    qsort(arr,n,sizeof(time), cmp);
    
    ll cnt = 0; ll last_t = 0;
    for(ll i = 0; i<n; i++){
        if(last_t <= arr[i].start){
            cnt++;
            last_t = arr[i].end;
        }
    }
    
    printf("%lld\n", cnt);
    return 0;
}
