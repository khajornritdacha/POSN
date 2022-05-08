#include <stdio.h>

main() {
    char ch;
    printf("Type one character ");
    ch = getchar();
    printf("The character you type is %c\n", ch);
    printf("The character you typed is ");
    putchar(ch);
}
