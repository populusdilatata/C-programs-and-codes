/* mzdova vycetka */
#include <stdio.h>
#include <conio.h>

int main()
{
	int i,j,castka,soucet;
        int platidla[12]={5000,2000,1000,500,200,100,50,20,10,5,2,1};
        int pocet[12];
        soucet=0;

	for (i=0;i<12;i++)
           pocet[i]=0;
        printf ("Zadejte castky k vyplate(pro konec -1):\n");
        do
        {
           scanf("%d",&castka);
           if(castka>0)
           {
              soucet=soucet+castka;
              for (i=0;i<12;i++)
                 while (castka>=platidla[i])
                 {
                    castka=castka-platidla[i];
                    pocet[i]++;
                 }
           }
        }           
        while(castka>=0);  
        printf ("soucet: %d\n",soucet);
        for (i=0;i<12;i++)
          printf("%d %d\n",platidla[i],pocet[i]);
       getch();
       return 0;
}
		
