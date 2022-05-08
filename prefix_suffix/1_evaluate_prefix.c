#include <stdio.h>
#include <string.h>

int MAXSIZE = 50;
int stack[80];
int top = -1;

int isempty()
{

    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek()
{
    return stack[top];
}

int pop()
{
    int data;
    if (!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data)
{

    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

int main()
{
    char prefixInput[] = "+9*26";

    for (int i = strlen(prefixInput) - 1; i >= 0; i--)
    {
        if (prefixInput[i] != '+' && prefixInput[i] != '-' && prefixInput[i] != '*' && prefixInput[i] != '/')
        {
            push(prefixInput[i]);
        }
        else
        {
            int op1 = pop() - '0';
            int op2 = pop() - '0';

            printf("%d %d\n", op1, op2);

            switch (prefixInput[i])
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            }
        }
    }

    printf("%d\n", peek());

    return 0;
}