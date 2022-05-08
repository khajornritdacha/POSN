#include<stdio.h>

main(){
    float rai,yarn,wa;
    scanf("%f %f %f", &rai, &yarn, &wa);
    printf("%.2f", (wa/400+yarn/4+rai)*0.3953);
}
