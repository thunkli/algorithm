#include <stdio.h>
int main (void)
{
    char ch;
    printf("please enter a character.\n");
    scanf("%c", &ch);
    printf("The code for %c is %d",ch,ch);
    return 0;
}