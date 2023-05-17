#include <stdio.h>
int main()
{
 int c[7][7]= {
 {0,6,5,5,100,100,100},
 {100,0,100,100,-1,100,100},
 {100,-2,0,100,1,100,100},
 {100,100,-2,0,100,-1,100},
 {100,100,100,100,0,100,3},
 {100,100,100,100,100,0,3},
 {100,100,100,100,100,100,0}
};


int d[100],pi[100],n,i,j,k,val,l;
printf("Enter the number of nodes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 d[i] = c[0][i];
 if(i != 0)
 {
  pi[i] = 1;
 }
}
pi[0]=0;

for(i=0;i<n-1;i++)
{
 for(j=0;j<n;j++)
 {
  for(k=0;k<n;k++)
  {
   val = d[j] + c[j][k];
   if(d[k] > val)
   {
    d[k] = val;
    pi[k] = j+1;
   }
  }
 }

 for(l=0;l<n;l++)
 {
  printf("\nd%d = %d",l,d[l]);
  printf("\tp%d = %d",l,pi[l]);
 }
 printf("\n");
}

for(i=0;i<n;i++)
{
 printf("\nd%d = %d",i,d[i]);
 printf("\tp%d = %d",i,pi[i]);
}

return 0;
}