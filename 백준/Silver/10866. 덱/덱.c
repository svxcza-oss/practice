#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10001
//연결리스트 기반으로 구현해보자

char result[200 * MAX];
int idx = 0;

typedef int Data;
typedef struct node{
    Data data;
    struct node * next;
    struct node * prev;
}Node;

typedef struct deque{
    Node * head;
    Node * tail;
    int size;
}DeQue;

void DeInit(DeQue * dq){
    dq -> head = NULL;
    dq -> tail = NULL;
    dq -> size = 0;
}

int DIsEmpty(DeQue * dq){
    return dq -> size == 0; // return 1이면 비어있다는거! 즉 참일때 비어있음
}

void DQaddF(DeQue * dq, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = dq -> head;
    
    if(DIsEmpty(dq))dq -> tail = newNode;
    else dq -> head -> prev = newNode;
    
    newNode -> prev = NULL;
    dq -> head = newNode;
    dq -> size++;
}

void DQaddL(DeQue * dq, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> prev = dq -> tail;
    
    if(DIsEmpty(dq)) dq -> head = newNode;//
    else dq -> tail -> next = newNode;
    
    newNode -> next = NULL;//
    dq -> tail = newNode;
    
    dq -> size++;
}

void DQreMF(DeQue * dq){
    if(DIsEmpty(dq)) {
        idx += sprintf(result + idx, "-1\n");
        return;
    }
    
    Node * rnode = dq -> head;//
    Data rdata;//
    
    //if(DIsEmpty(dq)) printf("-1\n");//예외처리
    rdata = dq -> head -> data;

    dq -> head = dq -> head -> next;//둘이 순서 주의
    
    if(dq -> head == NULL) dq -> tail = NULL;
    else dq -> head -> prev = NULL;
    
    free(rnode);//
    dq -> size--;
    idx += sprintf(result + idx, "%d\n", rdata);
    //return rdata;
}

void DQreML(DeQue * dq){
    if(DIsEmpty(dq)) {
        idx += sprintf(result + idx, "-1\n");
        return;
    }
    
    Node * rnode = dq -> tail;
    Data rdata;
    rdata = dq -> tail -> data;

    dq -> tail = dq -> tail -> prev;
    if(dq -> tail == NULL) dq -> head = NULL;
    else dq -> tail -> next = NULL;
    
    free(rnode);
    dq -> size--;
    
    idx += sprintf(result + idx, "%d\n", rdata);
    //return rdata;
}

int Size(DeQue * dq){
    return dq -> size;
}

void DQfront(DeQue * dq){
    if(DIsEmpty(dq)) idx += sprintf(result + idx, "-1\n");
    else idx += sprintf(result + idx, "%d\n", dq -> head -> data);
}

void DQback(DeQue * dq){
    if(DIsEmpty(dq)) idx += sprintf(result + idx, "-1\n");
    else idx += sprintf(result + idx, "%d\n", dq -> tail -> data);
}
    
void DQsize(DeQue * dq){
    idx += sprintf(result + idx, "%d\n", dq -> size);
}

void DQempty(DeQue * dq){
    idx += sprintf(result + idx, "%d\n", DIsEmpty(dq));
}


int main(void){
    int n;
    scanf("%d", &n);
    getchar();
    
    DeQue dq;
    DeInit(&dq);
    
    while (n--) {
            char str[100];
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';

            if (strncmp(str, "push_front", 10) == 0) {
                int num = atoi(str + 11);
                DQaddF(&dq, num);
            }
            else if (strncmp(str, "push_back", 9) == 0) {
                int num = atoi(str + 10);
                DQaddL(&dq, num);
            }
            else if (strcmp(str, "pop_front") == 0) DQreMF(&dq);
            else if (strcmp(str, "pop_back") == 0) DQreML(&dq);
            else if (strcmp(str, "front") == 0) DQfront(&dq);
            else if (strcmp(str, "back") == 0) DQback(&dq);
            else if (strcmp(str, "size") == 0) DQsize(&dq);
            else if (strcmp(str, "empty") == 0) DQempty(&dq);
        }

        printf("%s", result);
        return 0;
}
