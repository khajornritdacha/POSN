#include<stdio.h>
#include<string.h>

int n;
char c[1010];

int cal(int l, int r){
    if(l>=r){
        return 1;
    }
    if(c[l] == c[r]){
        return cal(l+1, r-1);
    }
    return 0;
}

int pa(int l, int r){
    if(l >= r)
        return 1;
    int res = cal(l, r);
    if(res == 0)
        return 0;
    return pa(l, r/2)+1;
}
main(){
    printf("Input String : ");
    scanf("%s", c);
    n = strlen(c);
    int ans = pa(0, n-1);
    printf("%s is %d-Palindrome", c, ans);
}
