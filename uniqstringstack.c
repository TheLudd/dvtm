#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

struct UniqueStack {
    char* data[MAX_STACK_SIZE];
    int top;
};

void stack_init(struct UniqueStack* s) {
    s->top = -1;
}

int stack_push(struct UniqueStack* s, const char* val) {
    if (s->top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        return 0;
    }
    for (int i = 0; i <= s->top; i++) {
        if (strcmp(s->data[i], val) == 0) {
            // move existing element to top of stack
            char* tmp = s->data[i];
            for (int j = i; j < s->top; j++) {
                s->data[j] = s->data[j + 1];
            }
            s->data[s->top] = tmp;
            return 1;
        }
    }
    s->data[++s->top] = strdup(val);
    return 1;
}

char* stack_pop(struct UniqueStack* s) {
    if (s->top == -1) {
        fprintf(stderr, "Error: Stack underflow\n");
        return NULL;
    }
    return s->data[s->top--];
}

char* stack_peek(struct UniqueStack* s) {
    if (s->top == -1) {
        fprintf(stderr, "Error: Stack underflow\n");
        return NULL;
    }
    return s->data[s->top];
}

void stack_print(struct UniqueStack *s)
{
    int i;
    printf("\nStack: ");
    for(i=0; i<=s->top; i++)
        printf("%s ", s->data[i]);
    printf("\n");
}
