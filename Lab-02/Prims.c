#include <stdio.h>
#include <limits.h>
#define Max 1000

int main()
{
    int n = 5, i, j;

    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    int visited[Max] = {0};
    int min, u = 0, v = 0, totalCost = 0, edges = 0;

       for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }
    visited[0] = 1;

    printf("Edge \tWeight\n");
    while (edges < n - 1)
    {
        min = INT_MAX;
        
        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (min != INT_MAX)
        {
            printf("%d - %d\t%d\n", u, v, min);
            totalCost += min;
            visited[v] = 1;
            edges++;
        }
    }

    printf("Total cost of MST: %d\n", totalCost);

    return 0;
}