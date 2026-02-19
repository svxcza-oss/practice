#include <stdio.h>
#include <string.h>


int main(void){
    int n,t; char str[10];
    int S = 0;
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++){
        scanf("%s", str);
        
        if(strcmp(str,"add") == 0){
            scanf("%d", &t);
            S |= (1<<t); //|연산. 둘중 하나라도 1이면 1(합집합)
        }
        else if(strcmp(str, "remove") == 0){
            scanf("%d", &t);
            S &= ~(1<<t); //&연산. 둘다 1이면 1(교집합)
        }
        else if(strcmp(str, "check") == 0){
            scanf("%d", &t);
            printf("%d\n", S&(1<<t) ? 1:0); //삼항연산자
        }
        else if(strcmp(str, "toggle") == 0){
            scanf("%d", &t);
            S ^= (1<<t); //xor연산. 비트반전 달라야 1
        }
        else if(strcmp(str, "all") == 0){
            S = (1 << 21) -1; //20으로 초기화
        }
        else if(strcmp(str, "empty") == 0){
            S = 0; //0으로 초기화
        }
    }
    
    return 0;
}

