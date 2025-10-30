#include <stdio.h>
#define V 8

void dfs(int graph[V][V], int visited[V], int key)
{
    printf("%d ", key + 1);
    visited[key] = 1;
    for (int i = 0; i < V; i++)
    {
        if (graph[key][i] && !visited[i])
        {
            dfs(graph, visited, i);
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
    int visited[V] = {0};
    dfs(graph, visited, 0);
    {
        int visited[V] = {0};
    }
}
