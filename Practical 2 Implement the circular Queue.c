#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// ---------- CHECKS ----------
int isFull()
{
    return (rear + 1) % MAX == front;
}

int isEmpty()
{
    return front == -1;
}

// ---------- ENQUEUE ----------
void enqueue(int val)
{
    if (isFull())
    {
        printf("Queue is Full! Cannot insert %d\n", val);
        return;
    }

    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = val;

    printf("Inserted %d\n", val);
}

// ---------- DEQUEUE ----------
void dequeue()
{
    int val;

    if (isEmpty())
    {
        printf("Queue is Empty! Cannot delete\n");
        return;
    }

    val = queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("Deleted %d\n", val);
}

// ---------- DISPLAY ----------
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

// ---------- MAIN ----------
int main()
{
    int choice, val;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");

                if (scanf("%d", &val) != 1)
                {
                    printf("Invalid input\n");
                    return 1;
                }

                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
