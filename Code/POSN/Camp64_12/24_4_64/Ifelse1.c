#include<stdio.h>

main(){
    float x,y;
    scanf("%f %f", &x, &y);
    if(y > 0){
        printf("%.1f", x+y);
    }else{
        printf("%.1f", x*y);
    }
}
