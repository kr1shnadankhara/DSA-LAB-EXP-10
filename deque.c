#include<stdio.h>
#include<conio.h>

#define MAX 10

int deque[MAX];
int left = -1, right = -1;

void input_deque();
void output_deque();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display();

void main()
{
    int option;
    clrscr();

    printf("\n*****MAIN MENU*****");
    printf("\n1. Input restricted deque");
    printf("\n2. Output restricted deque");
    printf("\nEnter your option : ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            input_deque();
            break;
        case 2:
            output_deque();
            break;
    }

    getch();
}

void input_deque()
{
    int option;
    do
    {
        printf("\n\nINPUT RESTRICTED DEQUE");
        printf("\n1. Insert at right");
        printf("\n2. Delete from left");
        printf("\n3. Delete from right");
        printf("\n4. Display");
        printf("\n5. Quit");
        printf("\nEnter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                insert_right();
                break;
            case 2:
                delete_left();
                break;
            case 3:
                delete_right();
                break;
            case 4:
                display();
                break;
        }
    } while(option != 5);
}

void output_deque()
{
    int option;
    do
    {
        printf("\n\nOUTPUT RESTRICTED DEQUE");
        printf("\n1. Insert at right");
        printf("\n2. Insert at left");
        printf("\n3. Delete from left");
        printf("\n4. Display");
        printf("\n5. Quit");
        printf("\nEnter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                insert_right();
                break;
            case 2:
                insert_left();
                break;
            case 3:
                delete_left();
                break;
            case 4:
                display();
                break;
        }
    } while(option != 5);
}

void insert_right()
{
    int val;
    printf("\nEnter the value to be added : ");
    scanf("%d", &val);

    if((left == 0 && right == MAX-1) || (left == right+1))
    {
        printf("\nOVERFLOW");
        return;
    }

    if(left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if(right == MAX-1)
            right = 0;
        else
            right = right+1;
    }
    deque[right] = val;
}

void insert_left()
{
    int val;
    printf("\nEnter the value to be added : ");
    scanf("%d", &val);

    if((left == 0 && right == MAX-1) || (left == right+1))
    {
        printf("\nOVERFLOW");
        return;
    }

    if(left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if(left == 0)
            left = MAX-1;
        else
            left = left-1;
    }
    deque[left] = val;
}

void delete_left()
{
    if(left == -1)
    {
        printf("\nUNDERFLOW");
        return;
    }

    printf("\nThe deleted element is : %d", deque[left]);

    if(left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if(left == MAX-1)
            left = 0;
        else
            left = left+1;
    }
}

void delete_right()
{
    if(left == -1)
    {
        printf("\nUNDERFLOW");
        return;
    }

    printf("\nThe deleted element is : %d", deque[right]);

    if(left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if(right == 0)
            right = MAX-1;
        else
            right = right-1;
    }
}

void display()
{
    int front = left, rear = right;

    if(front == -1)
    {
        printf("\nQUEUE IS EMPTY");
        return;
    }

    printf("\nThe elements of the deque are : ");

    if(front <= rear)
    {
        while(front <= rear)
        {
            printf("%d ", deque[front]);
            front++;
        }
    }
    else
    {
        while(front <= MAX-1)
        {
            printf("%d ", deque[front]);
            front++;
        }
        front = 0;
        while(front <= rear)
        {
            printf("%d ", deque[front]);
            front++;
        }
    }
    printf("\n");
}
