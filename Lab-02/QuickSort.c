#include <stdio.h>
#include <time.h>

void quickSort(int arr[], int low, int high)
{
    int pivot = arr[low];
    int lb = low;
    int ub = high + 1;

    lb++;
    while (lb < high && arr[lb] <= pivot)
    {
        lb++;
    }
    ub--;
    while (ub > low && arr[ub] >= pivot)
    {
        ub--;
    }
    while (lb < ub)
    {
        swap(&arr[lb], &arr[ub]);
    }
    lb++;
    while (lb < high && arr[lb] <= pivot)
    {
        lb++;
    }
    ub--;
    while (ub > low && arr[ub] >= pivot)
    {
        ub--;
    }
    swap(&arr[low], &arr[ub]);
    return 1;
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
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
    }

    if (readArrayFromFile("D:/DAA/Arrays/avg_case_100.txt", arr, N))
    {
        start = clock();
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time: %f ms\n", time_taken);
    }

    if (readArrayFromFile("D:/DAA/Arrays/wrost_case_100.txt", arr, N))
    {
        start = clock();
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time: %f ms\n", time_taken);
    }

    return 0;
}