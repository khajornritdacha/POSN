#include<stdio.h>

main(){
    int sc;
    scanf("%d", &sc);
    if(sc < 0 || sc > 100){
        printf("wrong score");
    }
    if(80 <= sc && sc <= 100){
        printf("A");
    }
    if(70 <= sc && sc <= 79){
        printf("B");
    }
    if(60 <= sc && sc <= 69){
        printf("C");
    }
    if(50 <= sc && sc <= 59){
        printf("D");
    }
    if(0 <= sc && sc <= 49){
        printf("F");
    }
}
