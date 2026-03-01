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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* temp = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        temp->next = createNode(sum % 10);
        temp = temp->next;
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
    int n1, n2, i, val;
    struct ListNode *l1 = NULL, *l2 = NULL, *temp = NULL;

    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &val);
        if (l1 == NULL) {
            l1 = createNode(val);
            temp = l1;
        } else {
            temp->next = createNode(val);
            temp = temp->next;
        }
    }

    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &val);
        if (l2 == NULL) {
            l2 = createNode(val);
            temp = l2;
        } else {
            temp->next = createNode(val);
            temp = temp->next;
        }
    }

    struct ListNode* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}