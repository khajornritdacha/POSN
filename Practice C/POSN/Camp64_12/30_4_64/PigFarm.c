#include<stdio.h>
float a[20];
main(){
    for(int i=1; i<=15; i++){
        scanf("%f", &a[i]);
    }
    while(1){
        int x;
        scanf("%d", &x);
        if(x < 1 || x > 15)
            break;
        printf("%.2f %.2f\n", a[x], a[x]*2.2);
    }
    printf("End");
}
