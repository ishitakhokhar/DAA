#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int readArrayFromFile(const char *filename, int arr[], int n)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("File not open\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
    return 1;
}

int main()
{
    int N = 100;
    int arr[N];
    int target = 42; // Example target, change as needed
    clock_t start, end;
    double time_taken;

    if (readArrayFromFile("D:/DAA/Arrays/best_case_100.txt", arr, N))
    {
        start = clock();
        int result = binarySearch(arr, N, target);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        if (result != -1)
            printf("Element %d found at index %d\n", target, result);
        else
            printf("Element %d not found in array\n", target);
        printf("Best Case Time: %f ms\n", time_taken);
    }

    return 0;
}