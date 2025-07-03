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

void deleteAtEnd(Node** head, Node** last) {
    if (*head == NULL) {
        printf("Danh sach rong");
        return;
    }

    int deleteValue = (*last)->data;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        *last = NULL;
    } else {
        Node* curr = *head;
        while (curr->next != *last) {
            curr = curr->next;
        }

        free(*last);

        curr->next = NULL;
        *last = curr;
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

    deleteAtEnd(&head, &last);

    printf("Danh sach sau xoa: ");
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