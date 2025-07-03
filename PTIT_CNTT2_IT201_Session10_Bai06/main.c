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

int findMidNode(Node** head) {
    if (*head == NULL) {
        return -1;
    }

    Node* slow = *head;
    Node* fast = *head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
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

    int mid = findMidNode(&head);
    printf("phan tu nam giua: %d\n",mid);

    Node* temp = head;
    Node* prev;
    while (temp != NULL) {
        prev = temp->next;
        free(temp);
        temp = prev;
    }

    return 0;
}