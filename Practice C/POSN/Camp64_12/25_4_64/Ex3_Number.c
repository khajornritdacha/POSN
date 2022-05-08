#include <stdio.h>
void OddEven (void);
void SignNum (void);
int num;
int main (void)
{
    printf("Enter number : ");
    scanf("%d",&num);
    OddEven( );
    SignNum( );
    getchar( );
    return(0);
}
void OddEven (void)
{
    if (num % 2 ) //num % 2 == 1
        printf("Number is odd\n");
    else
        printf("Number is even\n");
}
void SignNum ( void)
{
    if (num < 0)
        printf("number is negative\n");
    else if(num > 0)
        printf("number is positive\n");
    else
        printf("number is zero\n");
}
