#include <stdio.h>
#include <string.h>
#define MAX 100001

int main(void){
    char str[MAX];
    int cnt = 0;
    int top = 0;
    
    scanf("%s", str);
     
    int len = strlen(str);
        
    for(int i = 0; i<len; i++){
        if(str[i] == '(') str[top++] = '(';
        else{
            top --;
            if(str[i-1] == '(') {
                cnt += top;
            }
            else cnt++;
        }
    }
    printf("%d\n", cnt);
    
}
