#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

#define max(a,b) (a > b ? a : b)

typedef struct{
    int height;
    int count;
}StackD;

StackD Stack[MAX];
int top = -1;

int isEmpty(void){
    return top == -1;
}

void push(int h, int c){
    top ++;
    Stack[top].height = h;
    Stack[top].count = c;
}

void pop(void){
    top--;
}

StackD peek(void){
    return Stack[top];
}


//입력 마지막 신호기 0!
int main(void){
 
    while(1){
        int n;
        scanf("%d", &n);
        
        if(n == 0) {
            printf("\n");
            exit(0);
        }
        long long ans = 0;
        
        for(int i = 0; i<n; i++){
            int h; int idx = i;
            scanf("%d", &h);
            
            while(!isEmpty() && peek().height >= h ){
                ans = max(ans, 1LL * (i - peek().count) * peek().height);//가장 큰 결과값 반환
                idx = peek().count;
                pop();
            }
            push(h, idx);
            
        }
        
        while(!isEmpty()){
            ans = max(ans ,1LL * (n - peek().count) * peek().height);
            pop();
        }
       
        printf("%lld\n", ans);
        
    }
}
//제일 큰수를 저장하고 아니지 두번째로 큰수를 저장해야겠지 고점 & 반복횟수 저장 & 제일
