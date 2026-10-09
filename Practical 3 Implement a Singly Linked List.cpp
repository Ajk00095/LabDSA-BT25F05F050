#include <stdio.h>
#include <stdlib.h>

// ---------- NODE STRUCTURE ----------
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// ---------- CREATE NEW NODE ----------
struct Node *createNode(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

// ---------- INSERT AT BEGINNING ----------
void insertAtBeginning(int val)
{
    struct Node *newNode = createNode(val);

    newNode->next = head;
    head = newNode;

    printf("Inserted %d at beginning\n", val);
}

// ---------- INSERT AT END ----------
void insertAtEnd(int val)
{
    struct Node *newNode = createNode(val);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Inserted %d at end\n", val);
}

// ---------- INSERT AT GIVEN POSITION ----------
void insertAtPosition(int val, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insertAtBeginning(val);
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    struct Node *newNode = createNode(val);

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d\n", val, pos);
}

// ---------- DELETE BY VALUE ----------
void deleteByValue(int val)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->data == val)
    {
        struct Node *temp = head;

        head = head->next;
        free(temp);

        printf("Deleted %d\n", val);
        return;
    }

    struct Node *curr = head;

    while (curr->next != NULL && curr->next->data != val)
    {
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        printf("Value %d not found\n", val);
        return;
    }

    struct Node *toDelete = curr->next;

    curr->next = toDelete->next;
    free(toDelete);

    printf("Deleted %d\n", val);
}

// ---------- SEARCH ----------
int search(int val)
{
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return pos;
        }

        temp = temp->next;
        pos++;
    }

    return -1;
}

// ---------- DISPLAY ----------
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// ---------- FREE ALL NODES ----------
void freeList()
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// ---------- MAIN ----------
int main()
{
    int choice, val, pos;

    while (1)
    {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Search\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            freeList();
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Enter value: ");

                if (scanf("%d", &val) != 1)
                {
                    printf("Invalid input\n");
                    freeList();
                    return 1;
                }

                insertAtBeginning(val);
                break;

            case 2:
                printf("Enter value: ");

                if (scanf("%d", &val) != 1)
                {
                    printf("Invalid input\n");
                    freeList();
                    return 1;
                }

                insertAtEnd(val);
                break;

            case 3:
                printf("Enter value and position: ");

                if (scanf("%d %d", &val, &pos) != 2)
                {
                    printf("Invalid input\n");
                    freeList();
                    return 1;
                }

                insertAtPosition(val, pos);
                break;

            case 4:
                printf("Enter value to delete: ");

                if (scanf("%d", &val) != 1)
                {
                    printf("Invalid input\n");
                    freeList();
                    return 1;
                }

                deleteByValue(val);
                break;

            case 5:
                printf("Enter value to search: ");

                if (scanf("%d", &val) != 1)
                {
                    printf("Invalid input\n");
                    freeList();
                    return 1;
                }

                pos = search(val);

                if (pos != -1)
                {
                    printf("Found at position %d\n", pos);
                }
                else
                {
                    printf("Not found\n");
                }

                break;

            case 6:
                display();
                break;

            case 7:
                freeList();
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
