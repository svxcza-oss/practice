#include <stdio.h>
#include <stdlib.h>
//11724


typedef struct node{//구조체 노드 만들기
    int dest;//데이터?
    struct node * next; //간선
}NODE;

NODE * graph[1001];//인접리스트 저장할 배열
int visited[1001];//방문했던 곳 표시(방문노드 표시)

void addNode(int u, int v){//새로운 노드 추가
    NODE * newNode = (NODE*)malloc(sizeof(NODE));//공간할당
    newNode->dest = v;//데이터 넣기
    
    newNode -> next = graph[u];//다음 화살표가 u번째 인덱스 가르키기
    graph[u] = newNode;//거기 안에 또 노드 만들기
}

void DFS(int cur){
    visited[cur] = 1;//방문한 현위치 표시
    
    NODE * ptr = graph[cur];//현재 그래프 가르키는 포인터
    
    while(ptr != NULL){//끝까지 (NULL을 만날때까지)
        int next_node = ptr -> dest; //next_node에 현위치 포인터가 가르키는 값넣기
        
        if(visited[next_node] == 0) DFS(next_node);
        //만약 가르키는 값이 방문을 안했으면 재귀로 다시 방문
        ptr = ptr->next;//이미 방문한 값이면 다음으로 이동
    }
}

int main(void){
    int n,m; int cnt=0;
    scanf("%d %d",&n,&m);
    
    for(int i = 0; i<m; i++){
        int u,v;
        scanf("%d %d", &u,&v);
        
        addNode(u,v);//양방향 연결해주기
        addNode(v,u);
    }
    
    for(int i = 1; i<=n; i++){
        if(!visited[i]){//방문한곳 검사하고 덩어리 몇개인지 세기
            cnt++;
            DFS(i);
        }
    }
    printf("%d\n", cnt);
    return 0;
}

