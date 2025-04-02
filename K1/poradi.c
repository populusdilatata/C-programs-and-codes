/* poradi.c  ( inverzni permutace ) */
#define DIM 7
#include <stdio.h>
int klice[DIM]={3,5,7,1,4,2,6};
int data[DIM]={2,4,7,8,10,11,13};
void vymen(int *x,int*y)
{ int pom; pom=*x; *x=*y; *y=pom; }
int main()
{
  int i;
  for (i=0; i<DIM-1; i++)
  {
     while (i+1!=klice[i])
     {
        vymen (&data[i],&data[klice[i]-1]);   
        vymen (&klice[i],&klice[klice[i]-1]);
     }
  }
  printf("Vysledek:\n");
  for (i=0;i<DIM;i++)
     printf("%3d ",klice[i]);
  printf("\n");
  for (i=0;i<DIM;i++)
     printf("%3d ",data[i]);
  printf("\n");
  getch();
  return 0;
} 
