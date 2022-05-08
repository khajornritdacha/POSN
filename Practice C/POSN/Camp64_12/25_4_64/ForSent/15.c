#include <stdio.h>
#define d(X) X*2
#define a 1
#define total1 a+a
#define total2 total1-total1
main()
{
    int i;
    for( i=1; i<=2; i++)
    printf("Result ==> %d\n",d(i+1));
    printf("%d %d",total1,total2);
}
