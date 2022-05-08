#include <cstdio>

long long POWER(int a, int b, int m){
    if(b == 1)
        return a%m;
    long long x = POWER(a, b/2, m);
    if(b%2 == 0)
        return (x*x)%m;
    else if(b%2 == 1)
        return (x*x*a)%m;
}

int main(){
    int a, b, m;
    printf("Enter a,b,m: ");
    scanf("%d%d%d", &a, &b, &m);
    printf("%lld\n", POWER(a, b, m));
    return 0;
}
