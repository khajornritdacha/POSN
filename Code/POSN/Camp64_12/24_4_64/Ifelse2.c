#include<stdio.h>

main(){
    int sc;
    scanf("%d", &sc);
    if(sc < 0 || sc > 100){
        printf("wrong scores");
    }else if(sc >= 80){
        printf("A");
    }else if(sc >= 70){
        printf("B");
    }else if(sc >= 60){
        printf("C");
    }else if(sc >= 50){
        printf("D");
    }else{
        printf("F");
    }
}
