#include <stdio.h>
#include <conio.h>
main()
{
    char ch1[20], ch2[20];
    printf("\n Press any key1 :");
    gets(ch1);
    printf("\n Press any key2 :");
    gets(ch2);
    printf("\n Press any key in screen");
    getch();
    printf("\n Ascii value of ch is : %s %s\n",ch1,ch2);
    return 0;
}
