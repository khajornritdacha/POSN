#include<stdio.h>
int main(){
    char name[15];
    float grade;
    printf("What is your name ?\n");
    scanf("%s",&name);
    printf("Enter your GPA ");
    scanf("%f",&grade);
    printf("Hello %s, your GPA is %.2f\n",name,grade);
}
