#include <stdio.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
    }

    if (readArrayFromFile("D:/DAA/Arrays/avg_case_100000.txt", arr, N))
    {
        start = clock();
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time: %f ms\n", time_taken);
    }

    if (readArrayFromFile("D:/DAA/Arrays/wrost_case_100000.txt", arr, N))
    {
        start = clock();
        selectionSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time: %f ms\n", time_taken);
    }

    return 0;
}