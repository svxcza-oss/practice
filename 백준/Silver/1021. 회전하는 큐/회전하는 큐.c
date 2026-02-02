#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

typedef int Data;
typedef struct deque{
    Data List[MAX];
    int front;
    int rear;
    int size;
}Deque;

void DeQInit(Deque * dq){
    dq -> front = 0;
    dq -> rear = 0;
    dq -> size = 0;
}

Data DIsEmpty(Deque * dq){
    return dq -> size == 0;
}

Data DIsFull(Deque * dq){
    return dq -> size == MAX;
}

void DQaddF(Deque * dq, Data data){
    if(DIsFull(dq)) return;
    dq -> front = (dq -> front -1 + MAX) % MAX;
    dq -> List[dq -> front] = data;
    dq -> size ++;
}

void DQaddL(Deque * dq, Data data){
    if(DIsFull(dq)) return;
    dq -> List[dq -> rear] = data;
    dq -> rear = (dq -> rear + 1) % MAX;
    
    dq -> size ++;
}

Data DQreMF(Deque * dq){
    if(DIsEmpty(dq)) return -1;
    
    Data rdata = dq -> List[dq -> front];
    dq -> front = (dq -> front + 1) % MAX;
    
    dq -> size --;
    return rdata;
}

Data DQreML(Deque * dq){
    if(DIsEmpty(dq)) return -1;
    
    dq -> rear = (dq -> rear - 1 + MAX) % MAX;
    Data rdata = dq -> List[dq -> rear];
    
    dq -> size --;
    return rdata;
}

int DQSize(Deque * dq){
    return dq -> size;
}

int DQAt(Deque * dq, int idx){
    return dq -> List[(dq -> front + idx) % MAX];
}

int main(void){
    int n; int m;//덱 크기
    scanf("%d %d", &n, &m);
    
    int ops = 0;
    
    Deque dq;
    DeQInit(&dq);
    
    for(int j = 1; j<=n; j++){
        DQaddL(&dq, j);
    }
    
    for(int i = 0; i<m; i++){
        int target;
        scanf("%d", &target);
        
        int pos = 0;
        for(int k = 0; k<DQSize(&dq); k++){
            if(DQAt(&dq, k) == target){
                pos = k;
                break;
            }
        }
        int left = pos;
        int right = DQSize(&dq) - pos;
        
        if(left <= right){
            for(int z = 0; z<left; z++){
                int temp = DQreMF(&dq);
                DQaddL(&dq, temp);
                ops ++;
            }
            DQreMF(&dq);
        }
        else{
            for(int z = 0; z<right; z++){
                int temp = DQreML(&dq);
                DQaddF(&dq, temp);
                ops++;
            }
            DQreMF(&dq);
        }
        
    }
    printf("%d\n", ops);
    return 0;
    
}
