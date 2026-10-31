#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createList();
node *Insert_beg(node *head, int x);
node *Insert_end(node *head, int x);
node *Delete_beg(node *head);
node *Delete_end(node *head);
void PrintList(node *head);

void main()
{
    int choice, insert_option, delete_option, x;
    node *head = NULL;

    printf("Welcome to the implementation of the singly linked list !\n");
    do
    {
        printf("\nPlease select an operation to perform from the below list\n");
        printf(" 1. Create a List\n 2. Insert a node\n 3. Delete a node\n 4. Print the existing list\n 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                head = createList();
                break;

            case 2:
                do
                {
                    printf(" 1. Beginning of the List\n 2. End of the List\n 3. Exit the insert operation\n");
                    printf("Enter your choice: ");
                    scanf("%d", &insert_option);

                    switch(insert_option)
                    {
                        case 1:
                            printf("Enter the data to be inserted: ");
                            scanf("%d", &x);
                            head = Insert_beg(head, x);
                            break;

                        case 2:
                            printf("Enter the data to be inserted: ");
                            scanf("%d", &x);
                            head = Insert_end(head, x);
                            break;

                        case 3:
                            printf("Insert operation Exit");
                            break;

                        default:
                            printf("Please enter a valid choice: 1, 2, 3");
                    }
                } while(insert_option != 3);
                break;

            case 3:
                do
                {
                    printf("Select a position from where you want to delete the element\n");
                    printf(" 1. Beginning of the List\n 2. End of the List\n 3. Exit the delete operation\n");
                    printf("Enter your choice: ");
                    scanf("%d", &delete_option);

                    switch(delete_option)
                    {
                        case 1:
                            head = Delete_beg(head);
                            break;

                        case 2:
                            head = Delete_end(head);
                            break;

                        case 3:
                            printf("Delete Operation Exit");
                            break;

                        default:
                            printf("Please enter a valid choice: 1, 2, 3");
                    }
                } while(delete_option != 3);
                break;

            case 4:
                PrintList(head);
                break;

            case 5:
                printf("Exit: Program Finished !!");
                break;

            default:
                printf("Please enter a valid choice: ");
        }
    } while(choice != 5);

    getch();
}

node *createList()
{
    node *head, *p;
    int i, n;
    head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data: ");

    for(i = 0; i <= n-1; i++)
    {
        if(head == NULL)
            p = head = (node *)malloc(sizeof(node));
        else
        {
            p->next = (node *)malloc(sizeof(node));
            p = p->next;
        }
        p->next = NULL;
        scanf("%d", &(p->data));
    }
    return(head);
}

node *Insert_beg(node *head, int x)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = head;
    head = p;
    return(head);
}

node *Insert_end(node *head, int x)
{
    node *p, *temp;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;

    if(head == NULL)
        return(p);

    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = p;
    return(head);
}

node *Delete_beg(node *head)
{
    node *p;
    if(head == NULL)
    {
        printf("Empty Linked List");
        return(head);
    }
    p = head;
    head = head->next;
    free(p);
    return(head);
}

node *Delete_end(node *head)
{
    node *p, *q;
    if(head == NULL)
    {
        printf("Empty Linked List");
        return(head);
    }
    if(head->next == NULL)
    {
        free(head);
        return(NULL);
    }

    p = head;
    while(p->next->next != NULL)
        p = p->next;

    q = p->next;
    p->next = NULL;
    free(q);
    return(head);
}

void PrintList(node *head)
{
    node *p;
    printf("[ ");
    for(p = head; p != NULL; p = p->next)
        printf("%d \t", p->data);
    printf("]\n");
}
