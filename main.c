#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* listHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* listTail = listHead;
    listTail->val = 0;

    while (true) {
        int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + listTail->val;

        listTail->val = val % 10;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;

        if (l1 || l2 || val / 10) {
            listTail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            listTail = listTail->next;
            listTail->val = val / 10;
            listTail->next = NULL;
        } else {
            return listHead;
        }
    }
}

int main() {
    // Create two linked lists representing two non-negative integers
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    // Call the addTwoNumbers function and store the result
    struct ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }

    return 0;
}