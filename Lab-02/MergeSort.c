#include <stdio.h>
#include <time.h>

void merge(int arr[], int mid, int low, int high)
{
    int i, j, k;
    int arr2[high + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr2[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        arr2[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i <= high; i++)
    {
        arr[i] = arr2[k];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, mid, low, high);
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
    int N = 100;
    int arr[N];
    clock_t start, end;
    double time_taken;

    if (readArrayFromFile("D:/DAA/Arrays/best_case_100.txt", arr, N))
    {
        start = clock();
        insertionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
    }

    if (readArrayFromFile("D:/DAA/Arrays/avg_case_100.txt", arr, N))
    {
        start = clock();
        insertionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time: %f ms\n", time_taken);
    }

    if (readArrayFromFile("D:/DAA/Arrays/wrost_case_100.txt", arr, N))
    {
        start = clock();
        insertionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time: %f ms\n", time_taken);
    }

    return 0;
}