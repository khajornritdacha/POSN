#include<stdio.h>

int base,pw;

unsigned int Power(int b, int p){
    printf("= ");
    if(p == 0){
        for(int i=1; i<=pw; i++){
            printf("%d*",b);
        }
        printf("1\n");
        return 1;
    }
    for(int i=1; i<=pw-p+1; i++){
        printf("%d*",b);
    }
    printf("Power(%d,%d)\n", b, p-1);
    return b*Power(b, p-1);
}
main(){
    printf("Input Base Number : ");
    scanf("%d", &base);
    printf("Input Exponent Number : ");
    scanf("%d", &pw);
    printf("Power(%d,%d)\n", base, pw);
    printf("= %d\n", Power(base, pw));
}
