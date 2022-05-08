#include<stdio.h>
float ft,in;
main(){
    printf("Input length in Feets : ");
    scanf("%f", &ft);
    printf("%.2f\n", ft*30.48);
    printf("Input length in Inches : ");
    scanf("%f", &in);
    printf("%.2f\n", in*2.54);
    printf("Input length in Feets and Inches : ");
    scanf("%f %f", &ft, &in);
    printf("Sum of length in cm : %.2f\n", ft*30.48+in*2.54);
}
