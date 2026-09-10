#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
struct Node* reverseLinkedList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;  // 1. Save the next node
        curr->next = prev;  // 2. Reverse the current node's pointer
        prev = curr;        // 3. Move 'prev' one step forward
        curr = next;        // 4. Move 'curr' one step forward
    }
    
    // 'prev' ends up pointing to the new head of the reversed list
    return prev;
}

// Helper function to insert a node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Helper function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Constructing the list: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Original Linked List:\n");
    printList(head);

    // Reverse the list
    head = reverseLinkedList(head);

    printf("\nReversed Linked List:\n");
    printList(head);

    // Free allocated memory to avoid leaks
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}