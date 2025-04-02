/* hledej_min.c */
/* funkce hledej najde v poli index prvku s minimalni hodnotou */
#include <stdio.h>
#include <conio.h>
int hledej(int p[],int n)
{
   int i,min,imin;
   min=p[0]; imin=0;
   for(i=1;i<n;i++)
      if  (p[i]<min)
      {
          min=p[i]; imin=i;
      }
    return imin; /* vracím index prvku s minimální hodnotou */
}
int main()
{
   int p[10]={7,2,5,6,8,1,4,3,9,10};
   printf("Nejmensi prvek ma index:%d\n",hledej(p,10));
   getch();
   return 0;
}  
