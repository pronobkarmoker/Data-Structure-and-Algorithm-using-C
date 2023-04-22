#include <stdio.h>


void printarray(int *arr, int n);
void bubblesort(int *arr, int n);

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void bubblesort(int *arr, int n)
{
    int temp;
    int flag=0;
    for (int i = 0; i < n-1; i++)
    {
        flag =1;
        for (int j = 0; j < n - 1-i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag=0;
            }
        }
        if (flag)
        {
            return;
        }
        
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    //int arr[] = {12,54,65,7,23,9};
    int n = 6;
    printarray(arr, n);
    bubblesort(arr, n);
    printarray(arr, n);
    return 0;
}
