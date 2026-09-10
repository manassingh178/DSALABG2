#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to push a new node at the beginning
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to search for an element in the linked list
int search(struct Node* head, int key) {
    struct Node* current = head; // Initialize current
    int position = 1;

    while (current != NULL) {
        if (current->data == key)
            return position; // Found the key
        current = current->next;
        position++;
    }
    return 0; // Not found
}

int main() {
    struct Node* head = NULL;

    // Build the linked list: 10 -> 15 -> 4 -> 20 -> 5
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    int key = 15;
    int result = search(head, key);

    if (result != 0)
        printf("Element %d found at position %d.\n", key, result);
    else
        printf("Element %d not found in the linked list.\n", key);

    return 0;
}