#include<cstdio>
using namespace std;
int x,a[100000],n;
main(){
    scanf("%d",&n);
    for(int i=0;i<10;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<100;k++){
                int temp = (k*6)+(j*9)+(i*20);
                a[temp] = temp;
            }
        }
    }
    if(n<6){
        printf("no");
        return 0;
    }
    for(int i=1;;i++){
        if(a[i]>n)
            break;
        else if(a[i]!=0)
            printf("%d\n",a[i]);
    }
}
