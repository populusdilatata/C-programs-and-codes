/* kalendar.c */
#include <stdio.h>
short y,m,d;

int DenRoku(int y, int m, int d);
long PocDni(int y1,int m1,int d1,int y2, int m2,int d2);
short DenTydne(int y,int m, int d);
int DenRoku(int y, int m, int d)
{ 
  int k;
  k=((m-1)*30.57 +0.5) +d; 
  /* poèet dnu, které mají dohromady mesice 1 az m-1 plus den */
  if  (m>2)
  {
    k=k-2; /* oprava vypocteneho poctu dnu s ohledem na unor  */
    if ((y%4==0) && (y%100!=0) || (y%400==0)) k++; 
    /* zvetsit k pro prestupny rok */
  }
  return k;
}
long PocDni(int y1,int m1,int d1,int y2, int m2,int d2)
{    
  long k;
  k=365*(y2-y1);        /* „hrubý“ poèet dnù */
  k=k+DenRoku(y2,m2,d2)-DenRoku(y1,m1,d1); 
  /* zpøesnìní pomocí poøadových èísel */
  y2--; y1--;
  k=k+y2/4-y2/100+y2/400-y1/4+y1/100-y1/400;
  /* zpøesnìní s ohledem na pøestupné roky */
  return k; 
}
short DenTydne(int y,int m, int d)  
{  
  return PocDni(1599,12,26,y,m,d)%7;
}

int main()
{
  printf("Zadej rok,mesic,den\n");
  scanf("%d%d%d",&y,&m,&d); 
  switch (DenTydne(y,m,d))
  {
    case 0:
    {printf("nedele\n"); break;}
    case 1:
    {printf("pondeli\n"); break;}
    case 2:
    {printf("utery\n"); break;}
    case 3:
    {printf("streda\n"); break;}
    case 4:
    {printf("ctvrtek\n"); break;}
    case 5:
    {printf("patek\n"); break;}
    case 6:
    {printf("sobota\n");}
  }
  scanf("%d",&m);
}   

