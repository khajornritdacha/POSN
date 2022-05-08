#include <stdio.h>
int add (int x, int y)
{
    printf("x = %d , y = %d \n",x,y);
    return x+y;
}
int main ()
{
    int value_1 =1, value_2 = 2;
    printf("result : x + y = %d \n",
        add(value_1,value_2));
    return 0;
}
