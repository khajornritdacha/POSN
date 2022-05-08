#include <stdio.h>
#define PI 3.14159
float FindArea (float);
int main (void)
{
    float radius;
    printf("Enter radius of sphere:");
    scanf("%f",&radius);
    printf("area of sphere is %.2f",FindArea(radius));
    return 0;
}

float FindArea (float r)
{
    return 4*PI*r*r;
}
