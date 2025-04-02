/* preklop_nxn.c */
/* preklopi matici nxn podle hlavni diagonaly */
#include <stdio.h>

void CtiMat(float *m,int n)
/* nacteni ctvercove matice a typu n x n po radcich */
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("Zadej %d. radek matice\n",i);
		for(j=0;j<n;j++)
			scanf("%f",&m[n*i+j]);
	}
}

void TiskMat(float *m,int n)
/* tisk ctvercove  matice a typu n x n po radcich */
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%f ",m[n*i+j]);
		printf("\n");
	}
}

void Preklop(float *m, int n)
/* preklopeni ctvercove matice n x n podle hlavni diagonaly */
{
	int i,j;
	float pom;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			pom=m[i*n+j]; m[i*n+j]=m[j*n+i]; m[j*n+i]=pom;
		}
}

void main()
{
	float a[3][3];
	int pocet = 3;
	CtiMat(a,pocet);
	printf("Zadana matice: \n");
	TiskMat(a,pocet);
	Preklop(a,pocet);
	printf("Vysledna matice: \n");
	TiskMat(a,pocet);
	getch();
}



