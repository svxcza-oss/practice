#include <stdio.h>
#define MAX 10001

char star[MAX][2*MAX];

void print_star(int r,int c){
    star[r][c] = '*';
    star[r+1][c-1] = '*'; star[r+1][c+1] = '*';
    
    star[r+2][c-2] = '*'; star[r+2][c-1] = '*';
    star[r+2][c] = '*';
    star[r+2][c+1] = '*'; star[r+2][c+2] = '*';
}

void call_reculstar(int n, int x, int y ){
    if(n==3) {
        print_star(x,y);
        return;
    }
    
    int H = n/2;
    call_reculstar(H, x, y);
    call_reculstar(H,x+H, y-H);
    call_reculstar(H, x+H, y+H);
}

int main(void){
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<2*n; j++) star[i][j] = ' ';
    }
    
    call_reculstar(n,0,n-1);
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j< 2*n -1; j++){
            printf("%c", star[i][j]);
        }
        printf("\n");
    }
    return 0;
}
