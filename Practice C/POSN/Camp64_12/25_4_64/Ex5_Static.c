#include <stdio.h>
int inc(void);
int main (void) {
    int j;
    for (j=0; j < 10; j++)
        printf("You've called me %d times\n",inc());
    return 0;
}
int inc(void)
{
    static int k=0;
    return ++k;
}
