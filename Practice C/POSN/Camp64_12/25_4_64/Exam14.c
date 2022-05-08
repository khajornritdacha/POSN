#include<stdio.h>

int n,b[100],idx=0,mx=0;
char arr[100][100];

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}
int main(void){
    scanf("%d", &n);
    for(int i=0; i<90; i++){
        for(int j=0; j<90; j++){
            arr[i][j] = ' ';
        }
    }
    int tmp = n;
    while(tmp > 0){
        b[idx] = tmp%10;
        mx = max(mx, b[idx]);
        idx++;
        tmp/=10;
    }
    for(int i=idx-1,k=0; i>=0; i--,k++){
        for(int j=b[i]; j>0; j--){
            arr[mx-j][k] = '+';
        }
    }
    for(int i=0; i<mx; i++){
        for(int j=0; j<idx; j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}
