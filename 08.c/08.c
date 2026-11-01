
#include <stdio.h>
#include <string.h>

#define MAX_CITIES 20
#define INF 999999

int costMatrix[MAX_CITIES][MAX_CITIES];
char cityNames[MAX_CITIES][50];

int cityCount, flights;
int visited[MAX_CITIES];

char src[50], dest[50];
int cost;


// Function declarations
void initializeGraph();
int findCity(char name[]);
void addFlight();
void displayGraph();
void DFS(int city);
int checkConnectivity();


// Initialize graph
void initializeGraph()
{
    int i, j;

    for (i = 0; i < MAX_CITIES; i++)
    {
        for (j = 0; j < MAX_CITIES; j++)
        {
            if (i == j)
                costMatrix[i][j] = 0;
            else
                costMatrix[i][j] = INF;
        }
    }
}


// Find city index
int findCity(char name[])
{
    int i;

    for (i = 0; i < cityCount; i++)
    {
        if (strcmp(cityNames[i], name) == 0)
            return i;
    }

    return -1;
}


// Add flight
void addFlight()
{
    int u, v;

    u = findCity(src);
    v = findCity(dest);

    if (u == -1 || v == -1)
    {
        printf("City not found!\n");
        return;
    }

    costMatrix[u][v] = cost;
    costMatrix[v][u] = cost;

    printf("Flight added successfully!\n");
}


// Display adjacency matrix
void displayGraph()
{
    int i, j;

    printf("\nFlight Route Graph (Adjacency Matrix):\n\n");

    printf("%-12s", "");

    for (i = 0; i < cityCount; i++)
        printf("%-12s", cityNames[i]);

    printf("\n");

    for (i = 0; i < cityCount; i++)
    {
        printf("%-12s", cityNames[i]);

        for (j = 0; j < cityCount; j++)
        {
            if (costMatrix[i][j] == INF)
                printf("%-12s", "INF");
            else
                printf("%-12d", costMatrix[i][j]);
        }

        printf("\n");
    }
}


// Depth First Search
void DFS(int city)
{
    int i;

    visited[city] = 1;

    printf("%s ", cityNames[city]);

    for (i = 0; i < cityCount; i++)
    {
        if (costMatrix[city][i] != INF && !visited[i])
        {
            DFS(i);
        }
    }
}


// Check graph connectivity
int checkConnectivity()
{
    int i;

    for (i = 0; i < cityCount; i++)
        visited[i] = 0;

    if (cityCount == 0)
        return 0;

    printf("\nDFS Traversal: ");
    DFS(0);

    for (i = 0; i < cityCount; i++)
    {
        if (visited[i] == 0)
            return 0;
    }

    return 1;
}


// Main function
int main()
{
    int i;

    initializeGraph();

    printf("Enter number of cities: ");
    scanf("%d", &cityCount);

    if (cityCount <= 0 || cityCount > MAX_CITIES)
    {
        printf("Invalid number of cities!\n");
        return 1;
    }

    printf("\nEnter city names:\n");

    for (i = 0; i < cityCount; i++)
    {
        scanf("%49s", cityNames[i]);
    }

    printf("\nEnter number of direct flights: ");
    scanf("%d", &flights);

    if (flights < 0)
    {
        printf("Invalid number of flights!\n");
        return 1;
    }

    for (i = 0; i < flights; i++)
    {
        printf("\nEnter flight %d (Source Destination Cost): ", i + 1);

        scanf("%49s %49s %d", src, dest, &cost);

        addFlight();
    }

    displayGraph();

    if (checkConnectivity())
        printf("\n\nGraph is CONNECTED.\n");
    else
        printf("\n\nGraph is NOT CONNECTED.\n");

    return 0;
}
