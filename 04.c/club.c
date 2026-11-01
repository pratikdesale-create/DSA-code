
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int prn;
    char name[30];
    struct node *next;
};


// Create a new node
struct node* createNode()
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL)
        return NULL;

    printf("Enter PRN: ");
    scanf("%d", &newNode->prn);

    printf("Enter Name: ");
    scanf(" %29[^\n]", newNode->name);

    newNode->next = NULL;

    return newNode;
}


// Count members
int countMembers(struct node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}


// Insert node at any position
struct node* insertAtPosition(struct node *head, int pos)
{
    struct node *newNode, *temp;
    int i;

    if (pos < 1 || pos > countMembers(head) + 1)
    {
        printf("Invalid position.\n");
        return head;
    }

    newNode = createNode();

    if (newNode == NULL)
        return head;

    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}


// Delete node from any position
struct node* deleteAtPosition(struct node *head, int pos)
{
    struct node *temp, *prev;
    int i;

    if (pos < 1 || pos > countMembers(head))
    {
        printf("Invalid position.\n");
        return head;
    }

    temp = head;

    if (pos == 1)
    {
        head = head->next;
        free(temp);
        return head;
    }

    prev = head;

    for (i = 1; i < pos - 1; i++)
        prev = prev->next;

    temp = prev->next;
    prev->next = temp->next;

    free(temp);

    return head;
}


// Display members
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Club is empty.\n");
        return;
    }

    printf("\nPRN\tName\n");

    while (head != NULL)
    {
        printf("%d\t%s\n", head->prn, head->name);
        head = head->next;
    }
}


// Free allocated memory
void freeList(struct node *head)
{
    struct node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}


// Main function
int main()
{
    struct node *head = NULL;
    int choice, pos;

    do
    {
        printf("\n===== PINNACLE CLUB =====\n");
        printf("1. Add President\n");
        printf("2. Add Member\n");
        printf("3. Add Secretary\n");
        printf("4. Delete President\n");
        printf("5. Delete Member\n");
        printf("6. Delete Secretary\n");
        printf("7. Display Members\n");
        printf("8. Count Members\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = insertAtPosition(head, 1);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAtPosition(head, pos);
                break;

            case 3:
                head = insertAtPosition(head, countMembers(head) + 1);
                break;

            case 4:
                head = deleteAtPosition(head, 1);
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;

            case 6:
                head = deleteAtPosition(head, countMembers(head));
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Total members: %d\n", countMembers(head));
                break;

            case 9:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 9);

    freeList(head);

    return 0;
}
