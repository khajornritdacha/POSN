#include <stdio.h>
#include <math.h>

int main() {
    float radius; //radius of circle
    float pi = 22/7;
    printf("Enter radius : ");
    scanf("%f", &radius);
    float area =  pi*pow(radius, 2);
    printf("area of circle is %f", area);
    return 0;
}
