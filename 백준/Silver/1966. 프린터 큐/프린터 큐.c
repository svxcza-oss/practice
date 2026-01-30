#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
//1966

typedef struct Que{
    int idx[MAX];
    int val[MAX];
}que;


int main(void){
    int n; int a,b;
    scanf("%d", &n);
    que Q;
    
    for(int i = 0; i<n; i++){
        scanf("%d %d", &a,&b);
        int front =0; int rear =0;
        
        for(int j = 0; j<a; j++){
            scanf("%d", &Q.val[rear]);
            Q.idx[rear] = j;
            rear++;
        }
        
        int p_cnt=0;
        while(front < rear){
            int fin = 0;
            for(int k = front +1; k<rear; k++){
                if(Q.val[front] < Q.val[k]){
                    fin = 1;
                    break;
                }
            }
            if(fin == 1){
                Q.val[rear] = Q.val[front];
                Q.idx[rear] = Q.idx[front];
                rear++;front++;
            }
            else{
                p_cnt++;
                if(Q.idx[front] == b){
                    printf("%d\n", p_cnt);
                    break;
                }
                front++;
            }
        }
        
    }
    
}
         
