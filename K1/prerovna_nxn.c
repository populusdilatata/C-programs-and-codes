#include <stdio.h>

void CtiMat(int *m,int n)
/* nacteni ctvercove matice a typu n x n po radcich */
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("Zadej %d. radek matice\n",i);
		for(j=0;j<n;j++)
			scanf("%d",&m[n*i+j]);
	}
}

void TiskMat(int *m,int n)
/* tisk ctvercove  matice a typu n x n po radcich */
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",m[n*i+j]);
		printf("\n");
	}
}

void Prerovna(int *m, int n)
/* prerovna radky ctvercove matice n x n tak, aby na 1.radku */
/* byl radek s minimalni hodnotou v 1.sloupci                */
{
	int i,j;
	int pom,min,cr;
	min=m[0]; cr=0;
	/* vyhledani radku s min.prvkem v 1.sloupci, jeho index do cr */
	for(i=0;i<n;i++)
	{
		if (min>m[i*n])
		{
			min=m[i*n]; cr=i;
		}
	}
	/* printf ("%d %d\n",min,cr); */
	/* vymena 1.radku s radkem s min.prvkem v 1.sloupci */
		for(j=0;j<n;j++)
		{
			pom=m[j]; m[j]=m[cr*n+j]; m[cr*n+j]=pom;
		}
}

void main()
{
	int a[3][3]={{4,2,3},{4,1,7},{2,3,5}};
	int pocet = 3;
	//CtiMat(a,pocet);
	printf("Zadana matice: \n");
	TiskMat(a,pocet);
	Prerovna(a,pocet);
	printf("Vysledna matice: \n");
	TiskMat(a,pocet);
}



