#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

typedef int data;

typedef struct stack{
    int topindex;
    data D[MAX];
}StackD;


typedef StackD Stack;


void SStackInit(Stack * pstack){
    pstack -> topindex = -1;
}

int IsEmpty(Stack * pstack){
    if(pstack -> topindex == -1) return 1;
    else return 0;
}

int  Scount(Stack * pstack, int j){
    return pstack -> D[j];
}

void Push(Stack * pstack, data data){
    pstack -> topindex += 1;
    
    pstack -> D[pstack -> topindex] = data;
}


data Pop(Stack * pstack){
    if(IsEmpty(pstack)) {
        return -1;
    }
    data topdata = pstack -> D[pstack -> topindex];
    pstack -> topindex -= 1;
    
    return topdata;
}


// 0을 입력 받으면 팝 그리고 입력이 끝나면 모든 합 리턴

int main(void){
    int n;
    scanf("%d", &n);
    
    StackD pstack;
    SStackInit(&pstack);
    
    for(int i = 0; i<n; i++){
        int data;
        scanf("%d", &data);
        
        if(data == 0) Pop(&pstack);
        else{
            Push(&pstack, data);
        }
    }
    int res = 0;
    while(!IsEmpty(&pstack)) res += Pop(&pstack);
 
        
    printf("%d\n",res);
}

