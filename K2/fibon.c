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
          f1=f2;     /*  posledn� vypo�ten� se stane p�edposledn�m  */
          f2=nove;   /*   posledn�m je nov� vypo�ten�               */
          i++;       /*   kolik�t� Fibonacciho ��slo budeme po��tat */
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
