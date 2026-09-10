#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of the linked list
int getLinkedListLength(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    // Traverse the list until reaching NULL
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Helper function to insert a new node at the beginning
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;

    // Create a linked list: 10 -> 20 -> 30 -> 40
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    // Calculate and print the length
    int length = getLinkedListLength(head);
    printf("The length of the linked list is: %d\n", length);

    // Free the memory allocated for the linked list
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}