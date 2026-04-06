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
        printf("No documents to print\n");
        return;
    }
    printf("Printing document %d\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("No pending documents\n");
        return;
    }
    printf("Pending documents: ");
    int i;
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, doc;

    do {
        printf("\n1.Add\n2.\n3.Display\n4.Exit\n");
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
                break;
            default:
                printf("Invalid choice\n"); 
        }
    } while (choice != 4);

    return 0;
}