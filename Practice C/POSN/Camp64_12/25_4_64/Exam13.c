#include<stdio.h>

int n,num,arr[305][305],T=150,mn=1e9,mx=0;

int main(void){
    for(int i=0; i<300; i++){
        for(int j=0; j<300; j++){
            arr[i][j] = -1;
        }
    }
    printf("Enter Line : ");
    scanf("%d",&n);
    num = 1;
    int cnt = 1;
    for(int i=1,si=1; i<=n; i++,si*=-1){
        for(int j=0; j<i; j++){
            arr[i][T+j*si] = cnt;
            cnt++;
            cnt%=10;
            num++;
            if(T+j*si < mn){
                mn = T+j*si;
            }
            if(T+j*si > mx){
                mx = T+j*si;
            }
            if(num > n){
                for(int k=1; k<=i; k++){
                    for(int l=mn; l<=mx; l++){
                        if(arr[k][l] == -1){
                            printf(" ");
                        }else{
                            printf("%d",arr[k][l]);
                        }
                    }
                    printf("\n");
                }
                return 0;
            }
        }
    }
}
