
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct
{
    int key;
    char name[30];
    char phone[15];
    int occupied;
} Client;

Client hashTable[MAX];

/* Initialize Hash Table */
void initTable()
{
    int i;

    for(i = 0; i < MAX; i++)
        hashTable[i].occupied = 0;
}

/* Primary Hash Function */
int hashFunction(int key)
{
    return key % MAX;
}

/* Secondary Hash Function */
int hashFunction2(int key)
{
    return 7 - (key % 7);
}

/* Common Insertion Function */
void insertClient(int key, char name[], char phone[], int choice)
{
    int index = hashFunction(key);
    int step = hashFunction2(key);
    int i, pos;

    for(i = 0; i < MAX; i++)
    {
        if(choice == 1)
            pos = (index + i) % MAX;

        else if(choice == 2)
            pos = (index + i * i) % MAX;

        else
            pos = (index + i * step) % MAX;

        if(hashTable[pos].occupied == 0)
        {
            hashTable[pos].key = key;
            strcpy(hashTable[pos].name, name);
            strcpy(hashTable[pos].phone, phone);
            hashTable[pos].occupied = 1;

            printf("Client inserted at index %d\n", pos);
            return;
        }
    }

    printf("No empty slot found by this probing sequence.\n");
}

/* Search Client */
void search(int key)
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        if(hashTable[i].occupied && hashTable[i].key == key)
        {
            printf("\nClient Found!\n");
            printf("Name: %s\n", hashTable[i].name);
            printf("Phone: %s\n", hashTable[i].phone);
            printf("Index: %d\n", i);
            return;
        }
    }

    printf("Client not found!\n");
}

/* Display Hash Table */
void display()
{
    int i;

    printf("\n===== HASH TABLE =====\n");

    for(i = 0; i < MAX; i++)
    {
        if(hashTable[i].occupied)
            printf("%d: %d | %s | %s\n", i,
                   hashTable[i].key,
                   hashTable[i].name,
                   hashTable[i].phone);
        else
            printf("%d: Empty\n", i);
    }
}

/* Main Function */
int main()
{
    int choice, key;
    char name[30], phone[15];

    initTable();

    while(1)
    {
        printf("\n===== TELEPHONE BOOK =====\n");
        printf("1. Linear Probing\n");
        printf("2. Quadratic Probing\n");
        printf("3. Double Hashing\n");
        printf("4. Search Client\n");
        printf("5. Display Table\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            case 2:
            case 3:
                printf("Enter key, name and phone: ");
                scanf("%d %29s %14s", &key, name, phone);

                insertClient(key, name, phone, choice);
                break;

            case 4:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
