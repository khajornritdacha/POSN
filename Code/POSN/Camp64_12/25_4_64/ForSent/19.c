#include<stdio.h>
#define sum(x,y) (x)+(y)
#define dif(x,y) (x)-(y)
#define mul(x,y) (x)*(y)
#define div(x,y) (x)/(y)
#define mod(x,y) (x)%(y)

int a,b;
main(){
    printf("Input Number1 : ");
    scanf("%d", &a);
    printf("Input Number2 : ");
    scanf("%d", &b);
    printf("Summary\t\t== %d + %d\t= %d\n", a, b, sum(a,b));
    printf("Different\t== %d - %d\t= %d\n", a, b, dif(a,b));
    printf("Multiply\t== %d * %d\t= %d\n", a, b, mul(a,b));
    printf("Divide\t\t== %d / %d\t= %f\n", a, b, div(a*1.0,b));
    printf("Modulor\t\t== %d MOD %d\t= %d\n", a, b, mod(a,b));

}
