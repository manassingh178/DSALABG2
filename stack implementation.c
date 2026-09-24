#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void push(struct Node** top, int value);
int pop(struct Node** top);
int peek(struct Node* top);
int isEmpty(struct Node* top);
void display(struct Node* top);

int main() {
    // Initialize the top of the stack as NULL
    struct Node* stackTop = NULL;

    printf("--- Stack Using Linked List ---\n");

    // Push elements onto the stack
    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);

    // Display the current stack
    display(stackTop);

    // Peek the top element
    printf("Top element (Peek): %d\n\n", peek(stackTop));

    // Pop elements from the stack
    printf("Popped: %d\n", pop(&stackTop));
    printf("Popped: %d\n", pop(&stackTop));

    // Display stack after popping
    display(stackTop);

    // Clean up remaining elements to prevent memory leaks
    while (!isEmpty(stackTop)) {
        pop(&stackTop);
    }

    return 0;
}

// Function to push an element onto the stack (Insert at the beginning)
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if heap memory allocation failed
    if (newNode == NULL) {
        printf("Stack Overflow! Heap memory exhausted.\n");
        return;
    }

    newNode->data = value;
    newNode->next = *top; // Point new node to the current top
    *top = newNode;       // Move the top pointer to the new node
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack (Delete from the beginning)
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Return an error sentinel value
    }

    struct Node* temp = *top;  // Temporary pointer to hold current top
    int poppedValue = temp->data;

    *top = (*top)->next;       // Update top pointer to the next node
    free(temp);                // Deallocate memory of the old top node

    return poppedValue;
}

// Function to return the top element without removing it
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to print all elements in the stack
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* current = top;
    printf("Current Stack: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n\n");
}
