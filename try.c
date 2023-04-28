#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;               // Data of the node
    struct Node* next;     // Pointer to the next node in the linked list
};

// Function to create a new node with the given data
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to delete a node with the given data from the linked list
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return NULL;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node with data %d deleted from the linked list.\n", data);
        return head;
    }
    struct Node* prev = head;
    struct Node* curr = head->next;
    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Node with data %d not found in the linked list.\n", data);
        return head;
    }
    prev->next = curr->next;
    free(curr);
    printf("Node with data %d deleted from the linked list.\n", data);
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char* argv[]) {
    struct Node* head = NULL;  // Initialize an empty linked list

    // Insert numbers from argv into the linked list
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        head = insertAtEnd(head, num);
    }

    display(head);  // Display the linked list

    return 0;
}