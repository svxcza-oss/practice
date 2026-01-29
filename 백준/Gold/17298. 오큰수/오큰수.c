#include <stdio.h>
#define MAX 1000001
//17298

int arr[MAX];//입력받은 숫자 담는곳
int stack[MAX];//남길 값 저장
int res[MAX];//결과 저장

//탑문제와 비슷함. 그냥 거꾸로 한다고 생각하면 됨.
//거꾸로 입력받아서 값만 갱신.
int main(void){
    int n; int top = 0;
    scanf("%d", &n);

    for(int i = 0; i<n; i++) scanf("%d", &arr[i]);
    
    for(int i = n-1; i>=0; i--){
        while(top > 0 && stack[top] <= arr[i]) top--;
        /*
         탑문제에서는 왼쪽에서 바라보는 시점이였기 때문에 스택 정방향이였음
         근데 오큰수는 오른쪽 수를 기준으로 판단해야하기 때문에 배열의 끝부터 입력받으면서 작은수를 쳐냄.
         */
        if(top == 0) res[i] = -1; //큰수가 없다? -> -1 저장
        else res[i] = stack[top];//갱신된 큰 수를 결과에 저장
        
        stack[++top] = arr[i];//값 갱신
    }
    for(int i = 0; i<n; i++){
        printf("%d ", res[i]);//결과 출력
    }
}
