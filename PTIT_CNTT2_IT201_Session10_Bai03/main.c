#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addAtEnd(Node** head, Node** last, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        *last = newNode;
    } else {
        (*last)->next = newNode;
        *last = newNode;
    }
}

int main(void) {
    Node* head = NULL;
    Node* last = NULL;

    int arr[] = {24, 30, 4, 8, 3, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    printf("Danh sach ban dau: ");
    printList(head);

    int number;
    printf("Nhap vao 1 so bat ky: ");
    scanf("%d", &number);

    addAtEnd(&head, &last, number);
    printf("Danh sach sau khi them: ");
    printList(head);

    Node* temp = head;
    Node* prev;
    while (temp != NULL) {
        prev = temp->next;
        free(temp);
        temp = prev;
    }

    return 0;
}