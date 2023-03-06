#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack
{
    int data[MAX_SIZE];
    int top;
};

void init(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *s)
{
    if(s->top == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

void push(struct Stack *s, int element)
{
    if(isFull(s))
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        // If element already exists, move it to the top
        int i;
        for(i = 0; i <= s->top; i++)
        {
            if(s->data[i] == element)
            {
                int temp = s->data[i];
                s->data[i] = s->data[s->top];
                s->data[s->top] = temp;
                break;
            }
        }

        // If element doesn't exist, add it to the top
        if(i > s->top)
            s->data[++s->top] = element;
    }
}

int pop(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    {
        return s->data[s->top--];
    }
}

void printStack(struct Stack *s)
{
    int i;
    printf("\nStack: ");
    for(i=0; i<=s->top; i++)
        printf("%d ", s->data[i]);
    printf("\n");
}

// Driver program to test the above functions
int main()
{
    struct Stack s;
    init(&s);
    push(&s, 10);
    printStack(&s);
    push(&s, 40);
    printStack(&s);
    push(&s, 20);
    printStack(&s);
    push(&s, 40);
    printStack(&s);
    push(&s, 30);
    printf("%d popped from stack\n", pop(&s));
    printStack(&s);
    return 0;
}
