
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define SEATS 7

// Structure
struct node
{
    int seat_num, status;
    struct node *prev, *next;
};


// Create rows
int createRows(struct node *head[])
{
    struct node *temp, *newNode;
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        head[i] = NULL;
        temp = NULL;

        for (j = 0; j < SEATS; j++)
        {
            newNode = (struct node*)malloc(sizeof(struct node));

            if (newNode == NULL)
                return 0;

            newNode->seat_num = j;
            newNode->status = -1;
            newNode->prev = temp;
            newNode->next = NULL;

            if (temp == NULL)
                head[i] = newNode;
            else
                temp->next = newNode;

            temp = newNode;
        }
    }
    return 1;
}


// Find seat
struct node* findSeat(struct node *head, int seat)
{
    while (head != NULL && head->seat_num != seat)
        head = head->next;

    return head;
}


// Random booking
void randomBooking(struct node *head[])
{
    struct node *temp;
    int i, n, seat, count;

    for (i = 0; i < ROWS; i++)
    {
        n = rand() % 4 + 1;
        count = 0;

        while (count < n)
        {
            seat = rand() % SEATS;
            temp = findSeat(head[i], seat);

            if (temp->status == -1)
            {
                temp->status = 1;
                count++;
            }
        }
    }
}


// Display seats
void displaySeats(struct node *head[])
{
    struct node *temp;
    int i;

    for (i = 0; i < ROWS; i++)
    {
        printf("\nRow %d: ", i);

        temp = head[i];

        while (temp != NULL)
        {
            printf("%d:%c  ", temp->seat_num,
                   temp->status == 1 ? 'B' : '-');

            temp = temp->next;
        }
    }
    printf("\n");
}


// Book or cancel seat
void changeBooking(struct node *head[], int status)
{
    int row, seat;
    struct node *temp;

    printf("Enter Row (0-9): ");
    scanf("%d", &row);

    printf("Enter Seat (0-6): ");
    scanf("%d", &seat);

    if (row < 0 || row >= ROWS ||
        seat < 0 || seat >= SEATS)
    {
        printf("Invalid seat or row.\n");
        return;
    }

    temp = findSeat(head[row], seat);

    if (temp->status == status)
        printf("Operation not possible.\n");
    else
    {
        temp->status = status;

        printf(status == 1 ?
               "Seat booked successfully.\n" :
               "Booking cancelled successfully.\n");
    }
}


// Free memory
void freeMemory(struct node *head[])
{
    struct node *temp, *next;
    int i;

    for (i = 0; i < ROWS; i++)
    {
        temp = head[i];

        while (temp != NULL)
        {
            next = temp->next;
            free(temp);
            temp = next;
        }
    }
}


// Main function
int main()
{
    struct node *head[ROWS];
    int choice;

    srand(time(NULL));

    if (!createRows(head))
    {
        printf("Memory allocation failed.\n");
        freeMemory(head);
        return 1;
    }

    randomBooking(head);

    do
    {
        printf("\n\n===== CINEMAX THEATRE =====\n");
        printf("1. Display Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displaySeats(head);
                break;

            case 2:
                changeBooking(head, 1);
                break;

            case 3:
                changeBooking(head, -1);
                break;

            case 4:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    freeMemory(head);

    return 0;
}
