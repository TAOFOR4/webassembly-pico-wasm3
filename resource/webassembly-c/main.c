void reverseArray(int start, int end)
{
    int arr[] = {10, 20, 30, 40, 50};
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
