#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char c)
{
    if(top == MAX-1)
        printf("\nStack Overflow");
    else
    {
        top++;
        st[top] = c;
    }
}

char pop()
{
    char val = ' ';
    if(top == -1)
        printf("\nStack Underflow");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}

int getPriority(char op)
{
    if(op == '/' || op == '*' || op == '%')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    return 0;
}

void InfixToPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;

    while(source[i] != '\0')
    {
        if(source[i] == '(')
        {
            push(source[i]);
            i++;
        }
        else if(source[i] == ')')
        {
            while(top != -1 && st[top] != '(')
            {
                target[j] = pop();
                j++;
            }
            temp = pop();
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if(source[i]=='+' || source[i]=='-' || source[i]=='*' || source[i]=='/' || source[i]=='%')
        {
            while(top != -1 && st[top] != '(' && getPriority(st[top]) >= getPriority(source[i]))
            {
                target[j] = pop();
                j++;
            }
            push(source[i]);
            i++;
        }
        else
            i++;
    }

    while(top != -1)
    {
        target[j] = pop();
        j++;
    }
    target[j] = '\0';
}

void main()
{
    char infix[100], postfix[100];

    clrscr();
    printf("Enter an infix expression : ");
    gets(infix);

    InfixToPostfix(infix, postfix);

    printf("\nThe corresponding postfix expression is : %s", postfix);

    getch();
}
