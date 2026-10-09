#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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
    newNode->next = newNode;
    return newNode;
}

// Insert at beginning
void insertBeginning(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
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

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (head->next == head) {
        head = NULL;
    } else {
        struct Node *last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
    }

    printf("Deleted %d\n", temp->data);
    free(temp);
}

// Display
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

// Free all nodes
void freeList() {
    if (head == NULL)
        return;

    struct Node *temp = head->next;

    while (temp != head) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    free(head);
    head = NULL;
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
