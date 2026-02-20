#include <stdio.h>
#define MAX 100001

int main(void){
    int n,m; int arr[MAX] = {0,}; int val[MAX] = {0,};
    scanf("%d %d", &n, &m);

    for(int i = 1; i<=n; i++) scanf("%d", &arr[i]);
    val[1] = arr[1];
    val[2] = val[1] + arr[2];
    
    for(int i = 3; i<=n; i++){
        val[i] = val[i-1] + arr[i];
    }
    
    
    while(m--){
        int a,b;
        scanf("%d %d", &a, &b);
        
        printf("%d\n", val[b] - val[a-1]);
    }
    return 0;
}
