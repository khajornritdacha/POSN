#include<stdio.h>

int n,m;

int sum(int i){
    if(i < n)
        return 0;
    return i+sum(i-1);
}

main(){
    scanf("%d %d", &n, &m);
    printf("%d\n", sum(m));
}
