#include <stdio.h>

//2606
int cnt=0;

void DFS(int (*matrix)[101],int n,int visited[101],int v){
    visited[v] = 1;
    
    for(int i = 0; i<=n; i++){
        if(matrix[v][i] == 1 && visited[i] == 0) {
            cnt++;
            DFS(matrix,n,visited,i);
        }
    }
}

int main(void){
    int n; int matrix[101][101] = {0,};
    int visited[101] = {0,};
    scanf("%d", &n);
    
    int k;
    scanf("%d", &k);
    
    for(int i = 0; i<k; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    DFS(matrix,n,visited,1);
    printf("%d\n", cnt);
    return 0;
}
