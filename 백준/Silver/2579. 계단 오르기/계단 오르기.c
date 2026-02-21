#include <stdio.h>

int max(int a, int b) {return a > b ? a:b;}

int main(void){
    int n; int score[301];
    scanf("%d", &n);
    
    for(int i = 1; i<=n; i++) scanf("%d", &score[i]);
    
    int res[301] = {0,};
    
    res[1] = score[1];
    if (n>=2) res[2] = score[1] + score[2];
    if(n>=3) res[3] = max(score[1] + score[3], score[2] + score[3]);
    
    for(int i = 4; i<=n; i++) res[i] = max(res[i-2] + score[i], res[i-3] + score[i-1] + score[i]);
    printf("%d\n", res[n]);
    return 0;
}

