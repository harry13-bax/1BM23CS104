#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

struct Node* getMiddle(struct Node* head) {
    if (head == NULL) return head;
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* middle = slow->next;
    slow->next = NULL;
    return middle;
}

struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* middle = getMiddle(head);
    struct Node* left = mergeSort(head);
    struct Node* right = mergeSort(middle);

    return merge(left, right);
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    append(&list1, 3);
    append(&list1, 1);
    append(&list1, 4);
    append(&list1, 2);

    append(&list2, 6);
    append(&list2, 5);

    printf("Original List 1:\n");
    printList(list1);

    printf("Original List 2:\n");
    printList(list2);

    reverse(&list1);
    printf("\nReversed List 1:\n");
    printList(list1);

    concatenate(&list1, list2);
    printf("\nConcatenated List:\n");
    printList(list1);

    list1 = mergeSort(list1);
    printf("\nSorted List:\n");
    printList(list1);

    return 0;
}
