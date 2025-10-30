#include <stdio.h>
#include <time.h>

void heapify(int arr[], int n, int i)
{
    int maxIndex = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[maxIndex])
        maxIndex = left;
    if (right < n && arr[right] > arr[maxIndex])
        maxIndex = right;

    if (maxIndex != i)
    {
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
        heapify(arr, n, maxIndex);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
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
    int N = 100000;
    int arr[N];
    clock_t start, end;
    double time_taken;

    if (readArrayFromFile("D:/DAA/Arrays/best_case_100000.txt", arr, N))
    {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
    }

    if (readArrayFromFile("D:/DAA/Arrays/avg_case_100000.txt", arr, N))
    {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time: %f ms\n", time_taken);
    }

    if (readArrayFromFile("D:/DAA/Arrays/wrost_case_100000.txt", arr, N))
    {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time: %f ms\n", time_taken);
    }

    return 0;
}
