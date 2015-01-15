/*Given a linked list, remove the nth node from the end of list and return its head.*/

/*For example,

 * Given linked list: 1->2->3->4->5, and n = 2.

 * After removing the second node from the end, the linked list becomes 1->2->3->5.*/

 /* Note:
 * Given n will always be valid.
 * Try to do this in one pass.*/

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
 public:
   ListNode *removeNthFromEnd(ListNode *head, int n) {
     vector<ListNode*> nodeList;
     ListNode* node = head;

     while (node) {
       nodeList.push_back(node);
       node = node->next;
     }

     int nSize = nodeList.size();

     // the head and tail of a List should always be taken care of
     if (nSize == n) {
       head = head->next;
     } else if (n == 1) {
       nodeList[nSize - 2]->next = NULL;
     } else {
       nodeList[nSize - n - 1]->next = nodeList[nSize - n + 1];

     }
     return head;
   }
 };
