#include<stdio.h>

char c;
int n;

int main(void){
    printf("Enter Char : ");
    scanf("%c", &c);
    printf("Enter N : ");
    scanf("%d", &n);
    for(int i=1; i<=(n+1)/2; i++){
        for(int j=1; j<=(n+1)/2; j++){
            if(j<=i){
                printf("%c", c);
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<=(n+1)/2; j++){
            if(i+j > (n+1)/2){
                printf("%c", c);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i=1; i<(n+1)/2; i++){
        for(int j=1; j<=(n+1)/2; j++){
            if(i+j<=(n+1)/2){
                printf("%c",c);
            }else{
                printf(" ");
            }
        }
        printf(" ");
        for(int j=1; j<(n+1)/2; j++){
            if(j >= i){
                printf("%c", c);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
