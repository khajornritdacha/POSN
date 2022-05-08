#include<stdio.h>

main(){
    float x;
    for(int i=1; i<=10; i++){
        scanf("%f", &x);
        printf("%.2f\n", x*1.2);
    }
}
