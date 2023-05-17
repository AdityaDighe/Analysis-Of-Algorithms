#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void insertion_sort(int arr[], int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
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
    insertion_sort(arr,len);
    end=clock();
    printf("Average Case : %lf\n",(double)(end-start));
    
    start=clock();
    insertion_sort(arr,len);
    end=clock();
    printf("Best Case : %lf\n",(double)(end-start));
    
    reverse_array(arr,len);
    start=clock();
    insertion_sort(arr,len);
    end=clock();
    printf("Worst Case : %lf\n",(double)(end-start));

    //print_array(arr,len);
    
    return 0;
}