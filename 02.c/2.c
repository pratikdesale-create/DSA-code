
#include <stdio.h>

#define MAX 100

float percentage[MAX];

/* Selection Sort */
void selectionSort(int n)
{
    int i, j, minIndex;
    float temp;

    for(i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for(j = i + 1; j < n; j++)
        {
            if(percentage[j] < percentage[minIndex])
            {
                minIndex = j;
            }
        }

        temp = percentage[i];
        percentage[i] = percentage[minIndex];
        percentage[minIndex] = temp;
    }
}

/* Bubble Sort */
void bubbleSort(int n)
{
    int i, j;
    float temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(percentage[j] > percentage[j + 1])
            {
                temp = percentage[j];
                percentage[j] = percentage[j + 1];
                percentage[j + 1] = temp;
            }
        }
    }
}

/* Display Sorted Percentages */
void display(int n)
{
    int i;

    printf("\nSorted Percentages:\n");

    for(i = 0; i < n; i++)
    {
        printf("%.2f\n", percentage[i]);
    }
}

/* Display Top Five Percentages */
void displayTopFive(int n)
{
    int i, count = 0;

    printf("\nTop Five Percentages:\n");

    for(i = n - 1; i >= 0 && count < 5; i--)
    {
        printf("%.2f\n", percentage[i]);
        count++;
    }
}

/* Main Function */
int main()
{
    int n, i, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX)
    {
        printf("Invalid number of students.\n");
        return 0;
    }

    printf("\nEnter student percentages:\n");

    for(i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%f", &percentage[i]);
    }

    printf("\n===== SORTING MENU =====\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            selectionSort(n);
            printf("\nUsing Selection Sort");
            break;

        case 2:
            bubbleSort(n);
            printf("\nUsing Bubble Sort");
            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }

    display(n);
    displayTopFive(n);

    return 0;
}
