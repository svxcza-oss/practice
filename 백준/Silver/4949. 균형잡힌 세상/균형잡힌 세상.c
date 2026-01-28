#include <stdio.h>
#include <string.h>

 int main(void){
    //(),[]만 걸러서 입력받기
     char str[1100];
     char stack[1100];
     
     while(1){
         fgets(str,1100,stdin);
         int len = strlen(str);
         if(str[0] == '.' && (str[1] == '\n' || str[1] == '\0') ) break;
         
         int top = 0;
         int isT =1;
         
         for(int i = 0; i<len; i++){
             char ch = str[i];
             
             if(ch == '(' || ch == '['){
                 stack[top] = ch;
                 top++;
             }
             else if(ch == ')'){
                 if(top == 0 || stack[top-1] != '('){
                     isT = 0;
                     break;
                 }
                 top--;
            }
             else if(ch == ']'){
                 if(top == 0 || stack[top-1] != '['){
                     isT = 0;
                     break;
                 }
                 top--;
             }
         }
         if(isT == 1 && top == 0) printf("yes\n");
         else printf("no\n");
         
     }
 }

