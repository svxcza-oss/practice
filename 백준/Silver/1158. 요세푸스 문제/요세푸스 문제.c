#include <stdio.h>
#define MAX 40000001
//11866

int main(void){
    int n,m;
    scanf("%d %d", &n,&m);
    
    int rear=0; int front=0; int flag = 0; int arr[MAX];
    
    for(int i = 1; i<=n; i++){
        arr[rear++] = i;
    }
    
    printf("<");
    while(rear > front){
        for(int i = 0; i<m-1; i++){
            int flag = arr[front++]; //arr[1]값을 flag에 넣음 --> flag = 1
            arr[rear++] = flag; //arr[맨끝] = 1.
            /*계속 반복하면(예제 입력 7 3)
             2 3 4 5 6 7 1
             3 4 5 6 7 1 2
             m-1번 -> 2번 반복
             */
        }
        printf("%d", arr[front++]); //반복이 끝났음으로 3 출력.
        //그리고 front는 +1이 되므로 논리적으로 3은 없어짐.
        //4부터 다시 반복.
        if(front < rear) printf(", ");
    }
    printf(">");
    
}



