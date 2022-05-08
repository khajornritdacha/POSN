#include<stdio.h>

int n;

int Fac(int lv){
    printf("= ");
    if(lv == 0){
        for(int i=n; i>=1; i--){
            printf("%d*",i);
        }
        printf("1\n");
        return 1;
    }
    for(int i=n; i>=lv; i--){
        printf("%d*",i);
    }
    printf("Factorial(%d)\n", lv-1);
    return lv*Fac(lv-1);
}
main(){
    printf("Input Number : ");
    scanf("%d", &n);
    printf("Factorial(%d)\n", n);
    printf("= %d", Fac(n));
}
