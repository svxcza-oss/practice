#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100001
//5430

int nums[MAX];

void in_out(void){
    char cmd[MAX];
    scanf("%s", cmd);
    
    int n;
    scanf("%d", &n);
    
    char *arr = (char*)malloc(sizeof(char)* 400001);
    scanf("%s", arr);
    
    int idx = 0;
    if(n>0){
        char *ptr = strtok(arr, "[],\n");
        while(ptr != NULL){
            nums[idx++] = atoi(ptr);
            ptr = strtok(NULL, "[],\n");
        }
    }
    free(arr);
    
    int front = 0; int rear = n-1; int flag = 0; int error = 0;
    for(int i = 0; cmd[i]; i++){
        if(cmd[i] == 'R') flag = !flag;
        else if(cmd[i] == 'D'){
            if(front > rear) {
                error = 1;
                break;
            }
            if(flag == 0) front++;
            else rear--;
        }
    }
    
    
    if(error) printf("error\n");
    else{
        printf("[");
        if(flag == 0){
            for(int i = front; i<=rear; i++) {
                printf("%d", nums[i]);
                if(i < rear) printf(",");
            }
        }
        else {
            for(int i = rear; i>=front; i--) {
                printf("%d", nums[i]);
                if(i > front) printf(",");
            }
        }
        printf("]\n");
    }
    
}

int main(void){
    int t_n;
    scanf("%d", &t_n);
    while(t_n--) in_out();

    return 0;
}




