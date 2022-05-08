#include<stdio.h>

int seqsearch(int a[], int val, int n){
    int i=0;
    while(i<n){
        if(a[i] == val)
            return i;
        i++;
    }
    return -1;
}
main(){
    int a[5]={0,1,2,100,3,5};
    int pos = seqsearch(a, 4, 5);
    printf("%d\n", pos);
    pos = seqsearch(a, 2, 5);
    printf("%d\n", pos);
}
