#include<stdio.h>

main(){
    int n;
    scanf("%d", &n);
    if(n%2 == 0 && n < 0){
        printf("Both even and negative");
    }else if(n%2 == 0){
        printf("even");
    }else if(n < 0){
        printf("negative");
    }
}
