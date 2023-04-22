#include<stdio.h>
 void printarray(int *arr, int n);
 void insertionsort(int *arr ,int n);

int main(){
    int arr[] = {12,54,65,7,23,9};
    int n=6;
    insertionsort(arr , n);
    printarray(arr, n);
}

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void insertionsort(int *arr ,int n){
    for (int i = 1; i <= n-1; i++)
    {
        int temp=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        
        
    }
    
    
    }