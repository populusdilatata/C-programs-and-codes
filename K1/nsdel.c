/* nsdel.c -nejvetsi spolecny delitel */
#include <stdio.h>
#include <conio.h>

int nsd(int a,int b)
{
	if((a<=0) || (b<=0)) return 0;
	while(a>0)
	{
		if (a>b)
		  a-=b;
		else
		  b-=a; 
		if(b==0)return a;
	}
	return 0;
}	

int main()
{
	int x,y,d;
	printf ("Zadejte dve kladna cela cisla:\n");
	scanf ("%d%d",&x,&y);
	d=nsd(x,y);
	if(d>0)
	  printf("\nNejvetsi spol. delitel cisel %d a %d je %d.\n",x,y,d);
	getch();
	return 0;
}
