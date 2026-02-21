#include <stdio.h>

int main(void){
    int num;
    char op;
    int res = 0;
    int IsMinus = 0;
    
    if(scanf("%d", &num) == 1) res = num;
    
    while(scanf("%c%d", &op, &num) == 2){
        if(op == '-') IsMinus = 1;
        if(IsMinus) res -= num;
        else res += num;
    }
    
    printf("%d\n", res);
    return 0;
}

