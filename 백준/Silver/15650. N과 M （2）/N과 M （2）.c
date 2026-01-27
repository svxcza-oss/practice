#include <stdio.h>

int n,m;
int arr[10];

void dfsA(int dpt, int idx){
    if (dpt == m) {
        
        for(int i = 0; i<m; i++) printf("%d ", arr[i]);
    
        printf("\n");
        return;
    }
    
    for(int i = idx; i<=n; i++){ //깊이 탐색 재귀호출
        arr[dpt] = i;
        dfsA(dpt+1, i+1);
    }
}
/*핀 고정하면 중복 불허용
고정 안하면 중복 허용*/

int main(void){
    scanf("%d %d", &n,&m);
    dfsA(0,1);
    return 0;
}
