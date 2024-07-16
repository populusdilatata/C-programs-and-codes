#include <stdio.h>
#include <conio.h>
#define POCET 10

void insert(int p[],int n);
void bubble(int p[],int n);
void select(int p[],int n);
void shaker(int p[],int n);
void quick(int p[], int n);
void quicksnr(int p[], int n);
int merge(int p[],int q[],int n);
void shell(int p[],int n);

int main()
{
	int a[POCET]={8,3,7,1,10,5,6,4,2,9}; /* pole tridenych prvku */
	int pole[POCET];			/* vstupní pole pro trideni */
	int pole2[POCET];           /* pro mergesort */
	int pole3[POCET+1];         /* pro insertsort */
	int pocet=POCET;			/* vstupni parametr - pocet prvku */	
	int k;
	for (k=0; k<pocet; k++)		/* pole tridenych prvku presuneme */
		pole[k]=a[k];			/* do vstupniho pole pro trideni  */
	bubble(pole,pocet);
	printf("Setridene pole (bubblesort): \n");
	for (k=0; k<pocet; k++)		/* cyklus pro zobrazeni vysledku  */
		printf ("%d ",pole[k]); printf ("\n");

	for (k=0; k<pocet; k++)	    /* pole tridenych prvku presuneme */
		pole3[k+1]=a[k];		/* do vstupniho pole pro trideni  */
	insert(pole3,pocet);		/* zde pouziji o 1 delsi pole3    */	
	printf("Setridene pole (insertsort): \n");
	for (k=1; k<=pocet; k++)	/* cyklus pro zobrazeni vysledku  */
		printf ("%d ",pole3[k]); printf ("\n");

	for (k=0; k<pocet; k++)
		pole[k]=a[k];
	select(pole,pocet);	
	printf("Setridene pole (selectsort): \n");
	for (k=0; k<pocet; k++)
		printf ("%d ",pole[k]); printf ("\n");

	for (k=0; k<pocet; k++)
		pole[k]=a[k];
	shaker(pole,pocet);
	printf("Setridene pole (shakersort): \n");
	for (k=0; k<pocet; k++)
		printf ("%d ",pole[k]); printf ("\n");
	
	for (k=0; k<pocet; k++)
		pole[k]=a[k];
	quick(pole,pocet);
	printf("Setridene pole (quicksort): \n");
	for (k=0; k<pocet; k++)
		printf ("%d ",pole[k]); printf ("\n");

	for (k=0; k<pocet; k++)
		pole[k]=a[k];
	quicksnr(pole,pocet);
	printf("Setridene pole (quicksort nerekurzivni): \n");
	for (k=0; k<pocet; k++)
		printf ("%d ",pole[k]); printf ("\n");

	for (k=0; k<pocet; k++)
		pole[k]=a[k];
	merge(pole,pole2,pocet);
	printf("Setridene pole (mergesort): \n");
	for (k=0; k<pocet; k++)
		printf ("%d ",pole[k]); printf ("\n");

	for (k=0; k<pocet; k++)
		pole[k]=a[k];
	shell(pole,pocet);
	printf("Setridene pole (shellsort): \n");	
	for (k=0; k<pocet; k++)
		printf ("%d ",pole[k]); printf ("\n");
    scanf("%d",&k);     
	return 0;
}

void insert(int p[],int n)
/* trideni vkladanim - insertsort */
/* zde jsou tridene prvky ulozeny v poli od indexu 1 */
/* p[0] plni ulohu zarazky        */
{
int i,j;
for (i=2;i<=n;i++)
	{
	p[0] = p[i]; j = i-1;
	while (p[0] < p[j])
		{
			p[j+1] = p[j]; j--;
		}
		p[j+1] = p[0];
	}
}

void bubble(int p[],int n)
/* trideni pole vymenou - bubblesort */
{
	int i,j;	
	int x;						/* pomocna promenna pro vymenu */	
	for (i=1; i<n; i++)			
    /* v 1. pruchodu se dostane nejmensi prvek nahoru */
	{
	   for (j=n-1; j>=i; j--)
	   {
		 if (p[j-1] > p[j])		/* inverze - provede se vymena */
		 {
			x = p[j-1];
			p[j-1] = p[j];
			p[j] = x;
		 }
	   }
	}
}

void select(int p[],int n)
/* trideni pole primym vyberem - selectsort */
{
	int i,j,k;
	int x;						
	for (i=0; i<n-1; i++)
	{
		k=i; x=p[i];
		for (j=i+1; j<n; j++)
			if (p[j]<x)
			{
				k=j; x =p[j];
			}
		p[k]=p[i];p[i]=x; /* na i-te misto se dostal nejmensi prvek */
	}                         /* z mnoziny prvku i+1-ho az n-teho   */ 
}

void shell(int p[],int n)
/* trideni pole Shellovym algoritmem  */
{
int i,j,x,k,MaxK=1;
while (MaxK<n)
	MaxK=2*MaxK+1;
for(k=(MaxK-1)/2;k>0;k=(k-1)/2) 
/* tridime dilci posloupnosti s krokem k */
{                       /* na pr. vkladanim, krok k se postupne  */
	for (i=k;i<n;i++)   /* zmensuje az po hodnotu 1              */
		for  (j=i-k;j>=0;j-=k)
		{
			if (p[j] > p[j+k])
			{
				x=p[j+k]; p[j+k]=p[j]; p[j]=x;
			}
		}
}
}

void shaker(int p[],int n)
/* trideni pole pretrasanim - shakersort   */ 
/* vylepseni bublinkoveho sortu tim, ze se */
/* porovnava v obou smerech a pamatuji se  */
/* mista poslednich zmen; prohlizime jen   */
/* usek, kde jeste muze dojit k vymene     */
{
	int j,k,l,r;
	int x;
	l=1; r=k=n-1;
	do
	{
		for (j=r; j>=l; j--)  /* probublava nejmensi prvek nahoru */
		{
			if (p[j-1]>p[j])
			{
				x=p[j-1]; p[j-1]=p[j]; p[j]=x;
				k=j;			/* oznaceni, kde doslo ke zmene */
			}
		}
		l=k+1;					/* misto posledni zmeny shora   */
		if (l>r) return;
		for(j=l; j<=r; j++)		/* nejvetsi prvek dolu          */
		{
			if(p[j-1]>p[j])
			{
				x=p[j-1]; p[j-1]=p[j]; p[j]=x;
				k=j;			/* oznaceni, kde doslo ke zmene */
			}
		}
		r=k-1;					/* misto posledni zmeny zdola   */
	}
	while (l<=r);
}

void quick(int p[], int n)
/* trideni rozdelovanim - quicksort */
/* prvek x je vybran ze stredu tridene posloupnosti,  */
/* kterou rozdelime na dve podmnoziny; v prvni jsou   */
/* prvky mensi nez x, ve druhe vetsi; vznikle         */
/* useky tridime rekurzivne stejnym zpusobem.         */
{
	void quickc(int p[], int l, int r); 
    /* tridi usek od indexu l po r */
	quickc(p,0,n-1);
}

void quickc(int p[], int l, int r)
{
int i,j,x,y;

i=l; j=r;
x=p[(l+r)/2];
do
{
  while(p[i]<x && i<r)i++;
  while(p[j]>x && j>l)j--;
  if(i<=j)
  {
    if(i<j)
	{
      y=p[i]; p[i]=p[j]; p[j]=y;
	}
    i++; j--;
  }
} 
while(i<=j);
if(l<j) quickc(p,l,j);
if(i<r) quickc(p,i,r);
}

void quicksnr(int p[], int n)
/* quicksort - nerekurzivni verze */
/* velikost zasobniku pro uchovavani useku je rovna dvojkovemu    */
/* logaritmu z velikosti trideneho pole. Je ovsem nutno uchovavat */
/* vetsi useky.                                                   */
{
int zac[12],kon[12]; 
/* zasobniky pro oznaceni zacatku a koncu jednotl. useku */
int i,j,l,r;
int x,y;
int uk; /* ukazovatko v zasobnicich */
uk=0; zac[uk]=0; kon[uk]=n-1;
do {
	l=zac[uk]; r=kon[uk];
	uk--;
	i=l; j=r; x=p[(l+r)/2]; 
	do {
		while(p[i]<x && i<r)i++;
		while(p[j]>x && j>l)j--;
		if(i<=j)
		{
			if(i<j)
			{y=p[i]; p[i]=p[j]; p[j]=y;}
			i++; j--;
		}
	} while(i<=j);
		if ((j-l)<(r-i))
		{    /* levy usek je mensi */
		if(i<r) 
			{ /* uloz pravy usek do zasobniku */
				uk++; zac[uk]=i; kon[uk]=r;
				r=j;
			}
		}

		else
		{	/* pravy usek je mensi */
			if (j>l)
			{ /* uloz levy usek do zasobniku */
				uk++; zac[uk]=l; kon[uk]=j; 
				l=i;
			}
		}
}while (uk>=0);
}

int merge(int p[], int q[], int n)
/* trideni slucovanim - mergesort  */
/* algoritmus se lisi od standardniho postupu v tom,ze       */ 
/* nerozdeluji tridene pole na useky stejne velikosti, nybrz */
/* delitkem je inverze mezi sousednimi prvky. Algoritmus se  */
/* diky tomu chova prirozeneji. */
{
int * uk;	/* tady pamatovat ukazatel na pole p */
int * pom;	/* pro vymenu ukazatelu */
int i,j,k,m,l1,r1,l2,r2;
uk=p;
zac:m=0;
	while(m<n)
	{
		l1=m;r1=l1+1;
		/* urcim meze 1.serazeneho useku */
		while ((r1<n)&&(p[r1]>p[r1-1])) r1++;
		/* a urcim, neni/li to cele pole */
		if ((r1==n) &&  (l1==0))
		{
			if (pom==uk) /* je to pole p? */
			{
				for(k=0;k<n;k++)
					q[k]=p[k];
			}
			return 0; /* hotovo */
		}
		if (r1==n)
		{
			for (i=l1;i<r1;i++)
			{q[k]=p[i]; k++;}
			m=i+1;
		}
		else
		{
			l2=r1; r1--; r2=l2+1;
			while ((r2<n) && (p[r2]>p[r2-1])) r2++; /* 2. usek */
			r2--;
			i=l1; k=l1; j=l2;
			while ((i<=r1) && (j<=r2))
			{
				if (p[i] < p[j])
				{
					q[k]=p[i]; k++; i++;
				}
			    else
				{
			   	if (p[j] < p[i])
					{
				      	q[k]=p[j]; j++; k++;
			        }
				}
			}
         if (i>r1)
			{
				while (j<=r2)
				{ q[k]=p[j]; j++;  k++; } 
			}
         else
			if (j>r2)
			{
				while(i<=r1)
				{ q[k]=p[i]; i++; k++; }
			}
		 m=r2+1;	
		} 
	}
	pom=p;
	p=q;
	q=pom;
	goto zac;
} 

			
	     
       
