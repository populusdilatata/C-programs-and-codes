/* fibo1.c */
/* vypocet n-teho Fibonacciho cisla rekurzivne */
#include <stdio.h>
#include <conio.h>
int fibo(int n)
{
   if((n==0) || (n==1)) return n;
   else return(fibo(n-1)+fibo(n-2));
}
int main()
{
    int n;
    printf("zadejte n\n");
    scanf("%d",&n);
    printf("%d.Fib.cislo=%d\n",n,fibo(n));
    getch();
    return 0;
} 
