/* fibon.c */
/* vypocet n-teho Fibonacciho cisla bez pouziti rekurze */
#include <stdio.h>
#include <conio.h>
int fibon(int n)
{
   int f1,f2,nove,i;
   f1=0; f2=1;
   if (n<=1) return n;
   else
   {
      i=2;
      while (i<=n)
      {
          nove=f1+f2;       
          f1=f2;     /*  poslední vypoètené se stane pøedposledním  */
          f2=nove;   /*   posledním je novì vypoètené               */
          i++;       /*   kolikáté Fibonacciho èíslo budeme poèítat */
      }
      return nove;
   }
}
int main()
{
    int n;
    printf("zadejte n\n");
    scanf("%d",&n);
    printf("%d.Fib.cislo=%d",n,fibon(n));
    getch();
    return 0;
} 
