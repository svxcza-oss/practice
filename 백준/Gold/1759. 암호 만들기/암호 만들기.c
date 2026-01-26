#include <stdio.h>
#include <stdlib.h>

int n,m;
int input_line[26] = {0,};
char sorted[26];
int path[26];

int isT(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return 1;
    return 0;
}

void init_line(int m){
    int cnt = 0;
    
    for(int i = 0; i<m; i++){
        char temp;
        scanf(" %c", &temp);
        input_line[temp - 'a'] = 1;
    }
    
    for(int i = 0; i<26; i++){
        if(input_line[i] == 1){
            sorted[cnt] = i + 'a';
            cnt++;
        }
    }
}

void dfsA(int depth, int index){
    if(depth == n){
        int J = 0;
        int M = 0;
    
        for(int i = 0; i<n; i++){
            if(isT(path[i])) M++;
            else J++;
        }
        
        
        if(M >= 1 && J >=2){
            for(int i = 0; i<n; i++){
                printf("%c", path[i]);
            }
            printf("\n");
            return;
        }
    }
    for(int i = index; i<m; i++){
        path[depth] = sorted[i];
        dfsA(depth + 1, i + 1);
    }
}


int main(void){
    scanf("%d %d", &n,&m);
    
    init_line(m);
    dfsA(0,0);
    
    return 0;
    
}
