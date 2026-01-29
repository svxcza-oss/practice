#include <stdio.h>
//2493

int main(void){
    int n; int top = 0;
    scanf("%d", &n);
    int arr[n]; int stack[n]; int flag;

    for(int i = 1; i<=n; i++){
        scanf("%d", &flag); // flag 입력받기
        while(top > 0 && arr[top] < flag) top--;
        /*
         입력받은 flag보다 작은값은 arr에서 다 빼기
         */
        if(top == 0) printf("0 "); //아무것도 안남았다? -> 0
        else printf("%d ", stack[top]);//제일 큰 수만 남았기 때문에 해당 인덱스 출력
        
        top++; //다음 top에 다음 flag 저장
        arr[top] = flag;//값 갱신
        stack[top] = i;//최대값을 가진 인덱스 갱신
    }
}
