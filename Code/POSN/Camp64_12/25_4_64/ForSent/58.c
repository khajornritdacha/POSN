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
main(){
    printf("Input String : ");
    scanf("%s", c);
    n = strlen(c);
    int ans = cal(0, n-1);
    printf("%s is ", c);
    if(ans == 0){
        printf("not ");
    }
    printf("a Palindrome");
}
