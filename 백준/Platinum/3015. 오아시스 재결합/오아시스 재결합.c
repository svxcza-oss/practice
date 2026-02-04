#include <stdio.h>
#define MAX 500001
// 배열기반 스택

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

int main(void){
    int n; long long res = 0;
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++){
        int h; int cnt = 1;
        scanf("%d", &h);
        
        while(!isEmpty() && peek().height <= h){
            res += peek().count;
            
            if(peek().height == h) cnt += peek().count;
            pop();
        }
        
        if(!isEmpty()) res += 1;
        push(h,cnt);
    }
    printf("%lld", res);
    return 0;
}
