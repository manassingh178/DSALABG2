#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the stack

// Global variables for stack and tracking the top index
int stack[MAX];
int top = -1; // Initialize top to -1 indicating stack is empty

// Function to check if the stack is full
int isFull()
{
    if (top == MAX - 1)
    {
        return 1; // True
    }
    return 0; // False
}

// Function to check if the stack is empty
int isEmpty()
{
    if (top == -1)
    {
        return 1; // True
    }
    return 0; // False
}

// Function to add an element to the stack
void push(int value)
{
    if (isFull())
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        top++;
        stack[top] = value;
        printf("Successfully pushed %d onto the stack.\n", value);
    }
}

// Function to remove the top element from the stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1; // Error value
    }
    else
    {
        int poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}

// Function to view the top element without removing it
int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

// Function to display the stack elements
void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    // Test the Stack Operations
    printf("Checking initial state:\n");
    printf("Is empty? %s\n", isEmpty() ? "Yes" : "No");

    printf("\n--- Pushing Elements ---\n");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // Attempting to push to a full stack to trigger Overflow
    push(60);

    display();
    printf("Is full? %s\n", isFull() ? "Yes" : "No");
    printf("Top element (peek): %d\n", peek());

    printf("\n--- Popping Elements ---\n");
    printf("Popped value: %d\n", pop());
    printf("Popped value: %d\n", pop());

    display();

    return 0;
}