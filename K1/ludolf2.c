/* ludolf2.c */
/* urceni hodnoty Ludolfova cisla */
#include <conio.h>
#include <stdio.h>
int main()
{
   double pi,b,c;
   b=1; c=1; pi=4;
   while (4/b>0.00001)
   {
      c=-c; b+=2; pi+=c*4/b;
   }
   printf("vypoctena hodnota pi je %fl\n",pi);
   getch();
}
