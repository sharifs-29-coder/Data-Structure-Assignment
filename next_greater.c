#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], stack[MAX];
    int n, i, top = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Push first element
    stack[++top] = arr[0];

    for (i = 1; i < n; i++) {
        int next = arr[i];

        while (top != -1 && stack[top] < next) {
            printf("%d -> %d\n", stack[top--], next);
        }

        stack[++top] = next;
    }

    // Remaining elements
    while (top != -1) {
        printf("%d -> -1\n", stack[top--]);
    }

    return 0;
}