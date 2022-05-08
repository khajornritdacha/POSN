#include<stdio.h>

main(){
    float x1,x2,x3,ans,dis;
    scanf("%f %f %f", &x1, &x2, &x3);
    dis = (x1+x2+x3)*0.1;
    ans = (x1+x2+x3)-dis;
    printf("Total discount : %.2f\n", dis);
    printf("Net price : %.2f\n", ans);
}
