#include <stdio.h>
#define PI 3.14159
#define AREA(X) (4*PI*(X)*(X))

main (void)
{
    float radius;
    printf("Enter radius of sphere:");
    scanf("%f",&radius);
    printf("Area of sphere is %f\n"
        ,AREA(radius));
}
