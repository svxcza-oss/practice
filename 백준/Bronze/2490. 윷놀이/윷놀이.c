#include <stdio.h>

void arraycount(int arr[]){
    int count = 0;
    for(int i = 0; i<4; i++){
        if(arr[i] == 0) count++;
    }
    if(count == 1) printf("A\n");
    else if(count == 2) printf("B\n");
    else if(count == 3) printf("C\n");
    else if(count == 4) printf("D\n");
    else printf("E\n");
}

int main(){
    int arr1[4];
    int arr2[4];
    int arr3[4];
    
    for(int i = 0; i<4; i++) scanf("%d", &arr1[i]);
    for(int i = 0; i<4; i++) scanf("%d", &arr2[i]);
    for(int i = 0; i<4; i++) scanf("%d", &arr3[i]);
    
    arraycount(arr1);
    arraycount(arr2);
    arraycount(arr3);
    return 0;
    
}