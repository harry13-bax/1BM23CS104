#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            struct ListNode *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

struct ListNode* createNode(int val) {
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode *head) {
    struct ListNode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    head = deleteDuplicates(head);
    printList(head);

    return 0;
}
