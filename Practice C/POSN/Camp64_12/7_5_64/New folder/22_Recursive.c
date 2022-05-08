#include<stdio.h>

int a[5]={0,1,2,3,3,5};

int bisearch(int val, int low, int high){
    if(low > high)
        return -1;
    int mid = (low+high)/2;
    if(val == a[mid])
        return mid;
    else if(a[mid] > val)
        return bisearch(val, low, mid-1);
    else
        return bisearch(val, mid+1, high);
}
main(){
    int pos = bisearch(4, 0, 4);
    printf("%d\n", pos);
    pos = bisearch(3, 0, 4);
    printf("%d\n", pos);
}
