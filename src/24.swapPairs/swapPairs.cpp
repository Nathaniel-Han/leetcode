/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes
itself can be changed.*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *current = NULL, *tmp = NULL,
        *prev = NULL, *mHead = head;

        if (head != NULL && head->next != NULL) {
            tmp = head->next->next;
            head->next->next = head;

            mHead = head->next;
            head->next = tmp;
            prev = head;
            current = tmp;
        }

        while (current != NULL && current->next != NULL) {
            tmp = current->next->next;
            prev->next = current->next;
            current->next->next = current;
            current->next = tmp;

            prev = current;
            current = tmp;
        }
        return mHead;
    }
};

void DumpList(ListNode* head){
    ListNode* current = head;

    while (current != NULL) {
        std::cout << current->val << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    ListNode l1(1), l2(2), l3(3),l4(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;

    DumpList(&l1);

    Solution s;
    ListNode* node = s.swapPairs(&l1);

    DumpList(node);
    return 0;
}
