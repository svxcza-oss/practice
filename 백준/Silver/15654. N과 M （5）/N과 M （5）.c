#include <stdio.h>
int n,m;
int vistd[10];
int arr[10];
int result[10];

void dfsA(int dpt){
    if (dpt == m) {
    for(int i = 0; i<m; i++) printf("%d ", result[i]);
    
    printf("\n");
    return;
    }
    
    for(int i = 0; i<n; i++){ //깊이 탐색 재귀호출
        if(vistd[i] == 0){
            vistd[i] = 1;
            result[dpt] = arr[i]; //n과 m(1) 변형
            dfsA(dpt+1);
            
            vistd[i] = 0;
        }
    }
}


int main(void){
    scanf("%d %d", &n,&m);
    for(int i = 0; i<n; i++) scanf("%d", &arr[i]);
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    dfsA(0);
    return 0;
}

