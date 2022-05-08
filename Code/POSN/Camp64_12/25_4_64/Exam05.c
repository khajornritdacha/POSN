#include<stdio.h>

int a,b,c;

int main(void){
    printf("Enter a : ");
    scanf("%d", &a);
    printf("Enter b : ");
    scanf("%d", &b);
    printf("Enter c : ");
    scanf("%d", &c);
    printf("Result is :\n");
    int cnt = 0;
    for(int i=a; i<=b; i++){
        printf("%d\t", i);
        cnt++;
        if(cnt >= c){
            printf("\n");
            cnt = 0;
        }
    }
}
