#include<stdio.h>

int bisearch(int a[], int val, int n){
    int low=0, high=n-1, mid;
    while(low <= high){
        mid = (low+high)/2;
        if(a[mid] < val){
            low = mid+1;
        }else if(a[mid] > val){
            high = mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}
main(){
    int a[5]={0,1,2,3,3,5};
    int pos = bisearch(a, 4, 5);
    printf("%d\n", pos);
    pos = bisearch(a, 3, 5);
    printf("%d\n", pos);
}
