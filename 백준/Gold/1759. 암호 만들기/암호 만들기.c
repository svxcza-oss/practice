#include <stdio.h>
#include <stdlib.h>

int n,m;
int input_line[26] = {0,};
char sorted[26];
int path[26];

int isT(char c){//자음인지 판별하는 함수
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return 1;
    return 0;
}

void init_line(int m){//문자 정렬
    int cnt = 0;
    
    for(int i = 0; i<m; i++){//문자를 입력받아 배열에 알맞는 자리수 +1
        char temp;
        scanf(" %c", &temp);
        input_line[temp - 'a'] = 1;
    }
    
    for(int i = 0; i<26; i++){ //완성된 배열결과를 이용하여 정렬.
        if(input_line[i] == 1){
            sorted[cnt] = i + 'a';
            cnt++;
        }
    }
}

void dfsA(int depth, int index){//dfs를 이용해 조합 탐색
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
/*
  선형배열을 트리처럼 생각해서 원소를 하나씩 고정시키고 조건에 맞게 탐색해 조합.
  모든 경우의 조합을 찾아보고 조건에 맞는 결과만 출력함.
  */


int main(void){
    scanf("%d %d", &n,&m);
    
    init_line(m);
    dfsA(0,0);
    
    return 0;
    
}


