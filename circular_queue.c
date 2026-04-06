#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int doc) {
    if (rear == MAX - 1) {
        printf("Queue Full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = doc;
    printf("Document %d added\n", doc);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Removed document %d\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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