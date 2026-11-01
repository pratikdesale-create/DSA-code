
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    {
        hashTable[i].occupied = 0;
    }
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

/* Insert using Linear Probing */
void insertLinear(int key, char name[], char phone[])
{
    int index = hashFunction(key);
    int i, pos;

    for(i = 0; i < MAX; i++)
    {
        pos = (index + i) % MAX;

        if(hashTable[pos].occupied == 0)
        {
            hashTable[pos].key = key;
            strcpy(hashTable[pos].name, name);
            strcpy(hashTable[pos].phone, phone);
            hashTable[pos].occupied = 1;

            printf("Inserted at index %d using Linear Probing\n", pos);
            return;
        }
    }

    printf("Hash table full!\n");
}

/* Insert using Quadratic Probing */
void insertQuadratic(int key, char name[], char phone[])
{
    int index = hashFunction(key);
    int i, pos;

    for(i = 0; i < MAX; i++)
    {
        pos = (index + i * i) % MAX;

        if(hashTable[pos].occupied == 0)
        {
            hashTable[pos].key = key;
            strcpy(hashTable[pos].name, name);
            strcpy(hashTable[pos].phone, phone);
            hashTable[pos].occupied = 1;

            printf("Inserted at index %d using Quadratic Probing\n", pos);
            return;
        }
    }

    printf("Hash table full!\n");
}

/* Insert using Double Hashing */
void insertDoubleHash(int key, char name[], char phone[])
{
    int index = hashFunction(key);
    int step = hashFunction2(key);
    int i, pos;

    for(i = 0; i < MAX; i++)
    {
        pos = (index + i * step) % MAX;

        if(hashTable[pos].occupied == 0)
        {
            hashTable[pos].key = key;
            strcpy(hashTable[pos].name, name);
            strcpy(hashTable[pos].phone, phone);
            hashTable[pos].occupied = 1;

            printf("Inserted at index %d using Double Hashing\n", pos);
            return;
        }
    }

    printf("Hash table full!\n");
}

/* Search for a Client */
void search(int key)
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        if(hashTable[i].occupied && hashTable[i].key == key)
        {
            printf("\nClient Found!\n");
            printf("Name  : %s\n", hashTable[i].name);
            printf("Phone : %s\n", hashTable[i].phone);
            printf("Index : %d\n", i);
            return;
        }
    }

    printf("Client not found!\n");
}

/* Display Hash Table */
void display()
{
    int i;

    printf("\n-------- HASH TABLE --------\n");

    for(i = 0; i < MAX; i++)
    {
        if(hashTable[i].occupied)
        {
            printf("Index %d: Key=%d, Name=%s, Phone=%s\n",
                   i,
                   hashTable[i].key,
                   hashTable[i].name,
                   hashTable[i].phone);
        }
        else
        {
            printf("Index %d: Empty\n", i);
        }
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
        printf("1. Insert using Linear Probing\n");
        printf("2. Insert using Quadratic Probing\n");
        printf("3. Insert using Double Hashing\n");
        printf("4. Search Client\n");
        printf("5. Display Table\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);

                printf("Enter name: ");
                scanf("%29s", name);

                printf("Enter phone: ");
                scanf("%14s", phone);

                insertLinear(key, name, phone);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);

                printf("Enter name: ");
                scanf("%29s", name);

                printf("Enter phone: ");
                scanf("%14s", phone);

                insertQuadratic(key, name, phone);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);

                printf("Enter name: ");
                scanf("%29s", name);

                printf("Enter phone: ");
                scanf("%14s", phone);

                insertDoubleHash(key, name, phone);
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
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
