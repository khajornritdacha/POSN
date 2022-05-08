#include<stdio.h>

int id,im,iy,md[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
char namemonth[15][50] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int main(void){
    printf("Input Date : ");
    scanf("%d", &id);
    printf("Input Month : ");
    scanf("%d", &im);
    printf("Input Year : ");
    scanf("%d", &iy);
    id++;
    if(id > md[im]){
        id = 1;
        im++;
    }
    if(im == 13){
        im = 1;
        iy++;
    }
    printf("Tomorrow is : %d %s %d", id, namemonth[im], iy);
    return 0;
}
