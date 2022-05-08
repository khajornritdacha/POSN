#include<stdio.h>
int a,b;
main(){
    scanf("%d", &a);
    if(a%3 == 0){
        printf("%d\n", a);
        scanf("%d", &b);
        if(b%3 != 0){
            printf("%d\n", b);
        }else{
            printf("%d\n", a);
        }
    }else{
        printf("-1");
    }
}
