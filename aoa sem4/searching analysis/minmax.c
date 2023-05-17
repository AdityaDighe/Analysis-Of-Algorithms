#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int arr[10000];
int min,max;

void min_max(int i,int j)
{
    int max1,min1;
    int mid;

    if(i==j)
    {
        min=max=arr[i];
    }

    else
    {
        if(i==j-1)
        {
            if(arr[i]<arr[j])
            {
                max=arr[j];
                min=arr[i];
            }
            else
            {
                max=arr[i];
                min=arr[j];
            }
        }

        else
        {
            mid=(i+j)/2;
            min_max(i,mid);
            max1=min;
            max1=max;
            min_max(mid+1,j);
            if(min1<min)
            {
                min=min1;
            }
            if(max1>max)
            {
                max=max1;
            }
        }
    }
}

void main()
{
    int len;
    int i;
    clock_t start, end;

    printf("Enter the length of the array : ");
    scanf("%d",&len);
    for(i=0;i<len;i++)
    {
        arr[i]=rand()%len;
    }

    min=arr[0];
    max=arr[0];
    start=clock();
    min_max(1,len);
    end=clock();
    printf("MIN = %d\nMAX = %d\n",min,max);
    printf("Time taken : %lf\n",(double)(end-start));
    
    // for(i=0;i<len;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");

    getch();
}