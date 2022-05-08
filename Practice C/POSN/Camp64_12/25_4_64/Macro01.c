#include <stdio.h>
#define compare(n1,n2) ( (n1) > (n2) ? "more than": "less or equal")
int main (void)
{
    int n1, n2;
    printf("Enter 2 numbers : ");
    scanf("%d %d",&n1, &n2);
    printf("%d is %s %d \n",n1,compare(n1,n2),n2);
    return 0;
}
