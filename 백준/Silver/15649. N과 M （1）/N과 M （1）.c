#include <stdio.h>
int n,m;
int vistd[10];
int arr[10];

void dfsA(int dpt){
    if (dpt == m) {
    for(int i = 0; i<m; i++) printf("%d ", arr[i]);
    
    printf("\n");
    return;
    }
    
    for(int i = 1; i<=n; i++){ //깊이 탐색 재귀호출
        if(vistd[i] == 0){
            
            vistd[i] = 1;
            arr[dpt] = i;
            dfsA(dpt+1);
            
            vistd[i] = 0;
        }
    }
}


int main(void){
    scanf("%d %d", &n,&m);
    dfsA(0);
    return 0;
}
