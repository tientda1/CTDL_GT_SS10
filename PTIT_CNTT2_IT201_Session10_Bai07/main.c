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

void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    int swap;
    Node *ptr1, *ptr2 = NULL;

    do {
        swap = 0;
        ptr1 = *head;
        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swap);

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
    printf("danh sach ban dau: ");
    printList(head);

    sortList(&head);
    printf("Danh sach sau sap xep: ");
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