#include <stdio.h>
#include <conio.h>

main() {
    char ch1[50], ch2[50];
    printf("Press any key1 : ");
    gets(ch1);
    printf("Press any key2 : ");
    gets(ch2);
    printf("Press any key in screen : ");
    getch();
    printf("\nAscii value of ch is %s %s\n", ch1, ch2);
}
