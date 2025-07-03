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

void deleteNode(Node** head, Node** last, int value) {
    Node* curr = *head;
    Node* prev = NULL;
    while (curr != NULL) {
        if (curr->data == value) {
            Node* temp = curr;

            if (prev == NULL) {
                *head = curr->next;
                curr = *head;
            } else {
                prev->next = curr->next;
                curr = prev->next;
            }
            if (temp == NULL) {
                *last = prev;;
            }
            free(temp);
        } else {
            prev = curr;
            curr = curr->next;
        }
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

    int value;
    printf("Nhap so muon xoa: ");
    scanf("%d", &value);

    deleteNode(&head, &last, value);

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