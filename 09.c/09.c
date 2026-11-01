#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;
struct Node *temp, *newNode, *ptr;
int value, choice, n, i;
int mirrored = 0;

void createNode();
void insert();
void search();
void height();
void minimum();
void mirror();
void display();

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        insert();
    }

    while (1)
    {
        printf("\n===== BINARY SEARCH TREE =====\n");
        printf("1. Insert New Node\n");
        printf("2. Find Height of BST\n");
        printf("3. Find Minimum Value\n");
        printf("4. Mirror Tree\n");
        printf("5. Search a Value\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert();
                break;

            case 2:
                height();
                break;

            case 3:
                minimum();
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                {
                    mirror();
                    mirrored = !mirrored;
                    printf("Tree mirrored successfully.\n");
                }
                break;

            case 5:
                search();
                break;
            
            case 6:
                display();
                break;
                
            case 7:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void createNode()
{
    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

void insert()
{
    createNode();

    if (root == NULL)
    {
        root = newNode;
        printf("Root node inserted successfully.\n");
        return;
    }

    ptr = root;

    while (1)
    {
        if (value == ptr->data)
        {
            printf("Duplicate value is not allowed.\n");
            free(newNode);
            return;
        }

        if (value < ptr->data)
        {
            if (ptr->left == NULL)
            {
                ptr->left = newNode;
                break;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        else
        {
            if (ptr->right == NULL)
            {
                ptr->right = newNode;
                break;
            }
            else
            {
                ptr = ptr->right;
            }
        }
    }

    printf("Node inserted successfully.\n");
}

void search()
{
    printf("Enter value to search: ");
    scanf("%d", &value);

    ptr = root;

    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            printf("Element is found.\n");
            return;
        }

        if ((!mirrored && value < ptr->data) ||
            (mirrored && value > ptr->data))
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    printf("Element is not found.\n");
}

void height()
{
    struct Node *queue[1000];
    int front = 0, rear = 0;
    int h = 0, count, j;

    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    queue[rear++] = root;

    while (front < rear)
    {
        count = rear - front;
        h++;

        for (j = 0; j < count; j++)
        {
            ptr = queue[front++];

            if (ptr->left != NULL)
                queue[rear++] = ptr->left;

            if (ptr->right != NULL)
                queue[rear++] = ptr->right;
        }
    }

    printf("Longest path contains %d nodes.\n", h);
}

void minimum()
{
    int min;

    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    min = root->data;

    ptr = root;

    while (ptr != NULL)
    {
        if (ptr->data < min)
            min = ptr->data;

        if (!mirrored)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    printf("Minimum value = %d\n", min);
}

void mirror()
{
    struct Node *queue[1000];
    int front = 0, rear = 0;

    if (root == NULL)
        return;

    queue[rear++] = root;

    while (front < rear)
    {
        ptr = queue[front++];

        temp = ptr->left;
        ptr->left = ptr->right;
        ptr->right = temp;

        if (ptr->left != NULL)
            queue[rear++] = ptr->left;

        if (ptr->right != NULL)
            queue[rear++] = ptr->right;
    }
}


void display()
{
    struct Node *stack[1000];
    int top = -1;

    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    temp = root;

    printf("Inorder Traversal: ");

    while (temp != NULL || top != -1)
    {
        while (temp != NULL)
        {
            stack[++top] = temp;
            temp = temp->left;
        }

        temp = stack[top--];

        printf("%d ", temp->data);

        temp = temp->right;
    }

    printf("\n");
}