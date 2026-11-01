#include<stdio.h>

int linear_search(int roll[], int key, int i);
int binary_search(int roll[], int key, int i);

int main()
{
    int i,n,choice,result,key;
    int roll[100];
    do
    {
    printf("Welcome to the searching algorithm\n");
    printf("01.linear search\n");
    printf("02.binary search\n");
    printf("03.exit\n");

    printf("Enter ur choice:\n");
    scanf("%d",&choice);

    if(choice == 1 || choice == 2)
    {
        printf("Enter the number of students: \n");
        scanf("%d",&n);

        if(n<=0 || n>100)
        {
            printf("invalid no of students\n");
            continue;
        }
        if(choice == 1)
        {
            printf("Enter the roll no : \n");
        }
        else
        {
            printf("Enter the roll no in ascending order:\n");
        }
        for(i = 0; i<n ; i++)
        {
            scanf("%d",&roll[i]);
        }

        printf("Enter the roll no to search: \n");
        scanf("%d",&key);

        if(choice == 1)
        {
            result = linear_search(roll,key,i);
        }
        else
        {
            result = binary_search(roll,key,i);
        }

        if(result == -1)
        {
            printf("Roll not found \n");
        }
        else
        {
            printf("Roll no found at at index %d \n",result);
            printf("Position = %d\n",result+1);
        }
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

int linear_search(int roll[], int key, int n)
{
    
    int i;
    for(i=0 ; i < n; i++)
    {
        if(roll[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int roll[], int key,int n)
{
    
    int low =0 ;
    int high = n -1;
    int mid;

    while(low<=high)
    {
        mid = (low + high)/2;
        if(roll[mid]==key)
        {
            return mid;
        }
        else if(key<roll[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;

}