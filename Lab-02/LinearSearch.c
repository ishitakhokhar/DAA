#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int target)

{
    int n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
        return -1;
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
        linearSearch(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time: %f ms\n", time_taken);
    }

    return 0;
}