#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void write_best_case()
{
    FILE *f = fopen("best_case_100.txt", "w");
    for (int i = 1; i <= N; i++)
    {
        fprintf(f, "%d ", i);
    }
    fclose(f);
}

void write_wrost_case()
{
    FILE *f = fopen("wrost_case_100.txt", "w");
    for (int i = N; i >= 1; i--)
    {
        fprintf(f, "%d ", i);
    }
    fclose(f);
}

void write_avg_case()
{
    int arr[N];
    for (int i = 1; i <= N; i++)
    {
        arr[i - 1] = i;
    }
    // shuffle array
    for (int i = N - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    FILE *f = fopen("avg_case_100.txt", "w");
    for (int i = 0; i <= N; i++)
    {
        fprintf(f, "%d ", arr[i]);
    }
    fclose(f);
}

int main()
{
    write_best_case();
    write_wrost_case();
    write_avg_case();
}