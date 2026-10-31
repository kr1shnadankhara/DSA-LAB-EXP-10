/* Experiment No. 07
   Implementation of Graph Traversal (BFS and DFS)
   Real-world application: Social Network - finding friends/connections
   Each vertex is a person, each edge is a friendship (undirected graph) */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void addEdge(int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void bfs(int start)
{
    int queue[MAX], front = 0, rear = 0, i, v;

    for(i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for(i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

void main()
{
    int choice, u, v, i, j;

    clrscr();

    printf("Enter number of people (vertices): ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            adj[i][j] = 0;

    while(1)
    {
        printf("\n1. Add Friendship (Edge)\n2. BFS Traversal\n3. DFS Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the two persons (0 to %d): ", n - 1);
                scanf("%d %d", &u, &v);
                if(u < 0 || v < 0 || u >= n || v >= n)
                    printf("Invalid person\n");
                else
                    addEdge(u, v);
                break;

            case 2:
                printf("Enter starting person: ");
                scanf("%d", &u);
                printf("BFS: ");
                bfs(u);
                printf("\n");
                break;

            case 3:
                printf("Enter starting person: ");
                scanf("%d", &u);
                for(i = 0; i < n; i++)
                    visited[i] = 0;
                printf("DFS: ");
                dfs(u);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
