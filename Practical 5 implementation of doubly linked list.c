#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning(int data) {
    struct Node *newNode = createNode(data);

    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

// Insert at end
void insertEnd(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted %d\n", temp->data);
    free(temp);
}

// Display forward
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Free all nodes
void freeList() {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main
int main() {
    int choice, data;

    while (1) {
        printf("\n1. Insert Beginning\n2. Insert End\n");
        printf("3. Delete Beginning\n4. Display\n5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            freeList();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &data) != 1) {
                    freeList();
                    return 1;
                }
                insertBeginning(data);
                break;

            case 2:
                printf("Enter value: ");
                if (scanf("%d", &data) != 1) {
                    freeList();
                    return 1;
                }
                insertEnd(data);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                display();
                break;

            case 5:
                freeList();
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
