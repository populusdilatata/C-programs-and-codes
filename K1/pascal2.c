/* pascal2.c - zobrazi 12 radku Pascalova trojuhelnika */
#include <stdio.h>
#include <conio.h>
int main()
{
  int radek[13];
  int i,j;
  radek[0]=1; radek[1]=1;
  for(i=1;i<12;i++)
  {
    for(j=12;j>=i;j--) printf("   ");
    for(j=0;j<=i;j++) printf("%3d   ",radek[j]);
    printf("\n");
    for(j=i;j>0;j--) radek[j]=radek[j]+radek[j-1];
    radek[i+1]=1;
  }
  getch();
  return 0;
}
