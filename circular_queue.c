#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int doc) {
    // check if full
    if ((rear + 1) % MAX == front) {
        printf("Queue Full\n");
        return;
    }

    // first element
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = doc;
    printf("Document %d added\n", doc);
}

void dequeue() {
    // check if empty
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Removed document %d\n", queue[front]);

    // only one element
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, doc;

    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter document id: ");
                scanf("%d", &doc);
                enqueue(doc);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }

    } while (1);

    return 0;
}