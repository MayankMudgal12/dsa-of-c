#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *curr = head, *prev = &dummy;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, i, value, val;
    struct ListNode *head = NULL, *temp = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        if (head == NULL) {
            head = createNode(value);
            temp = head;
        } else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

    scanf("%d", &val);

    head = removeElements(head, val);
    printList(head);

    return 0;
}