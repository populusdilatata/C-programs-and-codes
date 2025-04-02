/* hanoj.c */
/* hanojske veze */
#include <stdio.h>
#include <conio.h>
int PVez(int vyska,int odkud,int kam,int pomoci)
{
	static int counter;
	counter++;
	if (vyska > 0)
	{
		PVez((vyska-1),odkud,pomoci,kam);
		printf("prenes kotouc z %i na %i\n", odkud,kam);
		PVez((vyska-1),pomoci,kam,odkud);
	}
	return counter;
}
int main()
{
	int n;
	int cnt;
	printf ("Zadej pocet kotoucu: \n");
	scanf("%i",&n);
	cnt=PVez(n,1,2,3);
	printf ("Pocet volani: %i\n",cnt);
	getch();
	return 0;
}
