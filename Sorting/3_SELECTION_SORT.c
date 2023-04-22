#include <stdio.h>
void printarray(int *arr, int n);
void selectionsort(int *arr, int n);

int main()
{
    int arr[] = {45, 67, 4, 34, 99, 23};
    int n = 6;
    selectionsort(arr, n);
    printarray(arr, n);
}

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// 1st value k min dhore nite hbe then swap
void selectionsort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
