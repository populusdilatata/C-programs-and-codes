/* fibo.c */
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

   int h;
   void b(int i);
   void c(int i);
   void d(int i);
   void a(int i)
   {
	   if (i>1)
	   {
		  a(i-1); linerel(h,0);  linerel(0,h);
               	  d(i-1); linerel(0,h);
           		  b(i-1); linerel(0,h);  linerel(-h,0); 
  a(i-1);
	   }
	   else linerel(0,h);
   }
   void b(int i)
   {
	   if (i>1)
	   {
		 b(i-1); linerel(0,h); linerel(-h,0);
        		 a(i-1); linerel(-h,0);
                             c(i-1); linerel(-h,0); linerel(0,-h);
                             b(i-1);
	   }
	   else linerel(-h,0);
   }
   void c(int i)
   {
	   if (i>1)
	   {
		 c(i-1); linerel(-h,0); linerel(0,-h);
                             b(i-1); linerel(0,-h);
                             d(i-1); linerel(0,-h); linerel(h,0);
                             c(i-1);
	   }
	   else linerel(0,-h);
   }
   void d(int i)
   {
	   if (i>1)
	   {
		 d(i-1); linerel(0,-h); linerel(h,0);
                              c(i-1); linerel(h,0);
                              a(i-1); linerel(h,0); linerel(0,h);
                              d(i-1);
	   }
	   else linerel(h,0);
   }
   int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* inicializace grafických a lokálních promìnných */
   initgraph(&gdriver, &gmode, "d:\\install\\bc\\bgi");

   /* ètení výsledku inicializace*/
   errorcode = graphresult();
   /* vyskytla se chyba */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Stiskni libovolnou klavesu");
      getch();
      exit(1);
   }

   setcolor(getmaxcolor());

   /* kresleni W-krivky */
   int n=6;
   int h0=640;
   int i,x0,y0;
   int rad;

   printf("Zadej rad krivky (1-6):\n");
   scanf("%i",&rad);
   i=0; h=h0/4; x0=2*h; y0=2*h;
   do
   {
	   i=i+1;
	   x0=x0-h; h=h/2; y0=y0+h;
	   if (i==rad)
	   {
                          moveto(x0+160,y0-160);
	            d(i); linerel(0,-h); linerel(h,0);
	            c(i); linerel(-h,0); linerel(0,-h);
	            b(i); linerel(0,h); linerel(-h,0);
	            a(i); linerel(h,0); linerel(0,h);
	   }
   }
   while(i<n);

   getch();
   closegraph();
   return 0;
}
