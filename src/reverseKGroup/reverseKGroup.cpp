/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k != 0) {
            vector<ListNode*> nodeArr(k, NULL);

            ListNode *mHead = head, *current = head,
            *inner_current=NULL, *prev = NULL, *tmp = NULL;

            if (current != NULL) {
                int i = 1;
                do {
                    nodeArr[i-1] = current;
                    current = current->next;
                    i++;
                } while (current != NULL && i != k+1);

                if (i == k+1) {
                    int j = k -1;
                    tmp = nodeArr[k-1]->next;
                    mHead = nodeArr[k-1];
                    while (j > 0) {
                        nodeArr[j]->next = nodeArr[j-1];
                        j--;
                    }
                    head->next = tmp;
                    prev = head;
                    current = tmp;

                }
                else
                    return head;
            }

            while(current != NULL){
                int i = 1;
                inner_current = current;

                 do {
                    nodeArr[i-1] = inner_current;
                    inner_current = inner_current->next;
                    i++;
                 }while (inner_current != NULL && i != k+1);

                if (i == k+1) {
                    int j = k-1;
                    tmp = nodeArr[k-1]->next;
                    prev->next = nodeArr[k-1];
                    while (j > 0) {
                        nodeArr[j]->next = nodeArr[j-1];
                        j--;
                    }
                    nodeArr[0]->next = tmp;
                    prev = nodeArr[0];
                    current = tmp;
                }
                else
                    return mHead;
            }
            return mHead;

        }
        else
            return head;
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
    ListNode l1(1), l2(2), l3(3),l4(4),l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    DumpList(&l1);

    Solution s;
    ListNode *node = s.reverseKGroup(&l1, 3);
    DumpList(node);
    return 0;
}
