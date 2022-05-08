#include<stdio.h>
main(){
    float h,w,BMI;
    printf("Input height(in metres) and weight(in kg) : ");
    scanf("%f %f", &h, &w);
    BMI = w/h/h;
    printf("Your BMI is : %.2f\n", BMI);
    if (BMI<18.5)
        printf("Underweight\n");
    else if (BMI<=22.9)
        printf("Slim\n");
    else if (BMI<=24.9)
        printf("Overweight\n");
    else if (BMI<=29.9)
        printf("Obesity\n");
    else
        printf ("Danger!\n");
}
