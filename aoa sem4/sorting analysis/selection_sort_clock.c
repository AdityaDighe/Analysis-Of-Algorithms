#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void selection_sort(int arr[], int n)
{
    int i,j;
    int min,temp;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

void reverse_array(int arr[],int n)
{
    int temp;
    int end=n,start=0;
    while(start<end)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void print_array(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    clock_t start,end;
    int len=10000;
    int arr[len];
    int i;
    
    for(i=0;i<len;i++)
    {
        arr[i]=rand()%len;
    }
    
    start=clock();
    selection_sort(arr,len);
    end=clock();
    printf("Average Case : %lf\n",(double)(end-start));
    
    start=clock();
    selection_sort(arr,len);
    end=clock();
    printf("Best Case : %lf\n",(double)(end-start));
    
    reverse_array(arr,len);
    start=clock();
    selection_sort(arr,len);
    end=clock();
    printf("Worst Case : %lf\n",(double)(end-start));

    //print_array(arr,len);
    
    return 0;
}