#include<stdio.h>

int linear_search(int roll[], int key, int n);
int binary_search(int roll[], int key, int n);

int main()
{
    int roll[100];
    int i,n,choice,result,key;

    do
    {
        printf("---Welcome to the searching algorithm---\n");
        printf("01.Linear search\n");
        printf("02.Binary search\n");
        printf("03. Exit\n");

        printf("Enter ur choice:\n");
        scanf("%d",&choice);

        if(choice == 1 || choice == 3)
        {
            printf("Enter the roll no of the students:\n");
            scanf("%d",&n);
        }
        if( n <= 0 || n > 100)
        {
            printf("invalid no of students \n");
            continue;
        }
        if(choice == 1)
        {
          printf("Enter the Roll no of students :\n");
        }
        else{
            printf("Enter the roll no in ascending order : \n");
        }
        for(i=0 ; i < n ; i++)
        {
            scanf("%d",&roll[i]);
        }

        printf("Enter the roll no to search:\n");
        if(choice == 1)
        {
            result = linear_search(roll,key,n);
        }
        else
        {
            result = binary_search(roll,key,n);
        }
        if(result == -1)
        {
            printf("Invalid no of students \n");
        }
        else
        {
            printf("Roll no found at index %d\n",result);
            printf("Position : %d",result + 1);
        }
        else if(choice == 3)
        {
            printf("Exiting the program\n");
        }
        else
        {
            printf("invalid choice");
        }
    } while(choice != 3);
      
    return 0;
}

int linear_search(int roll[],int key,int n)
{
    int i;
    for(i= 0 ; i <n ; i++)
    {
        while(array[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int roll[],int key,int n)
{
    int i;
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high)/2;
        if(roll[mid] == key)
        {
            return mid;
        }
        else if(roll[mid] < key)
        {
          low = mid + 1;
        }
        else
        {
           high = mid - 1;
        }
    }
    return -1;
}
   


    
    


