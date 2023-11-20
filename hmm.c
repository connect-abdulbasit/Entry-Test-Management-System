#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char a[100],c;
    int i;
    fflush(stdin);
    for ( i = 0 ; i<100 ; i++ )
    {

        fflush(stdin);
        c = getch();
        a[i] = c;
        if ( a[i] == ' ')
        {
            printf("\b \b");
            i-= 2;
            continue;
        }
        if ( a[i] == ' ' || a[i] == '\r' )
            printf(" ");
        else
            printf("*");
        if ( a[i]=='\r')
            break;
    }
    a[i]='\0';

    printf("\n%s" , a);
}