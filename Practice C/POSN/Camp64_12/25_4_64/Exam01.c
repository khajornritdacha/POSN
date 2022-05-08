#include<stdio.h>

float c;

int main(void){
    printf("Input degree in Celsius : ");
    scanf("%f", &c);
    printf("Degree in Fahrenheit is : %.1f", c*1.8+32);
    return 0;
}
