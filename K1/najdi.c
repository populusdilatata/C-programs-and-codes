
/* najdi.c */
/* funkce najdi hleda v poli zadanou hodnotu */
#include <stdio.h>
int p[10]={8,5,2,7,4,1,9,6,3,10};
   int n=10;
   int x;
int najdi(int p[],int n,int x)
   {
      int i;
      for(i=0;i<n;i++)
         if (x==p[i]) return i;
      return -1;                  /* hledaný prvek v poli není */
   }
int main()
{
   printf ("zadejte, co se ma hledat\n"); 
   scanf("%d",&x);
   printf ("index hledaneho je:%d\n",najdi(p,n,x));
   getch();
   return 0;
}  
