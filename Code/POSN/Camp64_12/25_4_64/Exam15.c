#include<stdio.h>

int a[15],sa,so,se,sp,sn;

int main(void){
    sa = so = se = sp = sn = 0;
    for(int i=0; i<10; i++){
        scanf("%d", &a[i]);
        sa += a[i];
        if(a[i]%2 == 0){
            se += a[i];
        }else{
            so += a[i];
        }
        if(a[i] > 0){
            sp += a[i];
        }else if(a[i] < 0){
            sn += a[i];
        }
    }
    printf("Total Sum : %d\n", sa);
    printf("Total Sum of Even Elements : %d\n", se);
    printf("Total Sum of Odd Elements : %d\n", so);
    printf("Total Sum of Positive Number Elements : %d\n", sp);
    printf("Total Sum of Negative Number Elements : %d\n", sn);
}
