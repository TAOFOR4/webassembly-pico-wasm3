#include <stdio.h>

#define SIZE 100

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[SIZE];

    // Initialize the array with some values
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = SIZE - i; // Example: Filling the array in descending order
    }

    bubbleSort(arr, SIZE);

    return 0;
}
