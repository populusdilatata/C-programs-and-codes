/* ludolf1.c */
/* urceni hodnoty Ludolfova cisla */
#include <stdio.h>
#include <conio.h>
int main()
{
    double pi1,pi2,a,b,c,q;
    a=4; b=3; c=-1; pi1=4; pi2=4.0-4.0/3.0;
    while (fabs(pi1-pi2)> 0.00001)   
    /* funkce fabs vrací absolutní hodnotu racionálního argumentu */
    {
        pi1=pi2; c=-c; b+=2.0;
        pi2=pi1+c*a/b;
    }
 printf ("vypoctena hodnota pi je %f\n",pi2);
 getch();
}
