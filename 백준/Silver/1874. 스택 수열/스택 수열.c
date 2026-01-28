#include <stdio.h>
#define MAX 100001

int main(void){
    int n,top=1;
    int target,num = 1;
    int arr[MAX];
    char res[MAX*2];
    int res_idx = 0;
    int flag = 1;
    scanf("%d", &n);
   
    for(int i = 0; i<n; i++){
        scanf("%d", &target);
        
        while(num <= target){
            arr[top++] = num;
            num++;
            res[res_idx++] = '+';
        }
        if(top > 0 && arr[top-1] == target){
            top--;
            res[res_idx++] = '-';
        }
        else{
            flag = 0;
            break;
        }
    }
    
    if(flag == 0) printf("NO\n");
    else{
        for(int i = 0; i<res_idx; i++){
            printf("%c\n", res[i]);
        }
    }
    
}
