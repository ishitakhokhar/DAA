#include <stdio.h>
#define V 8

void bfs(int graph[V][V])
{
    int queue[V], visited[V] = {0};
    int count = 0;

    queue[count++] = 0;
    visited[0] = 1;

    int i = 0;
    while (i < count)
    {
        int node = queue[i++];
        printf("%d ", node + 1);

        for (int j = 0; j < V; j++)
        {
            if (graph[node][j] && !visited[j])
            {
                queue[count++] = j;
                visited[j] = 1;
            }
        }
    }
}

int main()
{
    int graph[V][V] = {
        {0, 1, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0},
    };
}