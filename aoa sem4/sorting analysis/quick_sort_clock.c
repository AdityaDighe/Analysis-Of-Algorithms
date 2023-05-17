#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1,j;
    int temp;

    for(j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;  
        }
    }
    temp=arr[high];
    arr[high]=arr[i+1];
    arr[i+1]=temp;
    return i+1;
}

void quick_sort(int arr[], int low, int high)
{
    int pi;
    if(low<high)
    {
        pi=partition(arr,low,high);

        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
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
    quick_sort(arr,0,len);
    end=clock();
    printf("Average Case : %lf\n",(double)(end-start));
    
    start=clock();
    quick_sort(arr,0,len);
    end=clock();
    printf("Best Case : %lf\n",(double)(end-start));
    
    reverse_array(arr,len);
    start=clock();
    quick_sort(arr,0,len);
    end=clock();
    printf("Worst Case : %lf\n",(double)(end-start));

    //print_array(arr,len);
    
    return 0;
}