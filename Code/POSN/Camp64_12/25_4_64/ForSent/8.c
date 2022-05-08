#include <stdio.h>
char get_char (void); //prototyped
char any_char; //Global Variables
int main () //Main program
{
    printf("Please type a character:");
    printf("Thank you. the character was %c", get_char ());
    return 0;
}
char get_char (void) //Function
{
    scanf("%c",&any_char); return any_char;
}
