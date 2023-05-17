#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void merge(int arr[],int start,int mid,int end)
{
    int i,j,k;
    int n1=mid-start+1;
    int n2=end-mid;
    int L[10000],R[10000];

    for(i=0;i<n1;i++)
    {
        L[i]=arr[start+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[mid+1+j];
    }

    i=0,j=0,k=start;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }

        k++;
    }

    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int start, int end)
{
    int mid;
    if(start<end)
    {
        mid=(start+end)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
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
    merge_sort(arr,0,len);
    end=clock();
    printf("Time taken : %lf\n",(double)(end-start));
    
    //print_array(arr,len);
    
    return 0;
}