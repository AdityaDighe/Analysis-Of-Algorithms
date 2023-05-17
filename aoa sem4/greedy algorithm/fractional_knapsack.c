#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<limits.h>

struct object
{
  int value;
  int weight;
};

void main()
{
    struct object p[]={{1,2},{2,3},{3,4},{4,5},{5,6}};
    int capacity=10;
    
    int n=sizeof(p)/sizeof(p[0]);
    float ratio[100]={0};
    
    for(int i=0;i<n;i++)
    {
        ratio[i]=(float)p[i].value/(float)p[i].weight;
    }
    
    float solarray[100]={0};
    
    while(capacity!=0)
    {
        int max=INT_MIN;
        int index;
        for(int i=0;i<n;i++)
        {
            if(max<ratio[i])
            {
                max=ratio[i];
                index=i;
            }
        }
        
        if(p[index].weight<capacity)
        {
            ratio[index]=INT_MIN;
            capacity=capacity-p[index].weight;
            solarray[index]=1;
        }
        else
        {
            ratio[index]=INT_MIN;
            solarray[index]=(float)capacity/(float)p[index].weight;
            capacity=0;
        }
    }
    
    int total=0;
    for(int i=0;i<n;i++)
    {
        if(solarray[i]!=0)
        {
            printf("%d : %f\n",p[i].value,solarray[i]);
            total=total+p[i].value;
        }
    }
    printf("The Max value : %d\n",total);
}
