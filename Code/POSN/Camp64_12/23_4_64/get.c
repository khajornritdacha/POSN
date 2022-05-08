#include<stdio.h>
#include<conio.h>

int main ()
{
    char text[80];
    printf("Input Text : ");
    gets(text);
    putchar('\n');
    puts(text);
    getch();
    return 0;
}
