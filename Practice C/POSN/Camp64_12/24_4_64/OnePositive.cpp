#include<stdio.h>

main(){
    int x,y,cnt=0;
    scanf("%d %d", &x, &y);
    if(x > 0){
        cnt++;
    }
    if(y > 0){
        cnt++;
    }
    if(cnt == 1){
        printf("one positive\n");
    }
}
