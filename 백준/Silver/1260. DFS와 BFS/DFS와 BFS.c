#include <stdio.h>
#define MAX 1001

//1260
void BFS(int (*matrix)[MAX], int n, int visited[], int v){//너비우선 탐색(그냥 옆에 있는거)
    int q[MAX];
    int front = 0; int rear = 0;
    
    visited[v] = 1;
    q[rear++] = v;
    
    while(front < rear){
        int cur = q[front++];
        printf("%d ",cur);
        
        for(int i = 1; i<= n; i++){
            if(matrix[cur][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

void DFS(int (*matrix)[MAX], int n, int visited[], int v){//깊이우선 탐색(행끼리 건너뛰기)
    visited[v] = 1;
    printf("%d ", v);
    
    for(int i = 1; i<=n; i++){
        if(matrix[v][i] == 1 && visited[i] == 0) DFS(matrix,n,visited,i);
    }
}

int main(void){
    int n,m,v;
    scanf("%d %d %d", &n,&m,&v);
    
    int matrix[MAX][MAX] = {0,};
    int visited[MAX] = {0,};
    
    for(int i = 0; i<m; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    DFS(matrix,n,visited,v);
    printf("\n");
    
    for(int i = 0; i<=n; i++) visited[i] = 0;
    
    BFS(matrix,n,visited,v);
    printf("\n");
    
    return 0;
}

