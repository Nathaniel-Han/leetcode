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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (lenOfList(l1) > lenOfList(l2))
			return addTwoNumbers(l2, l1);

		int sum;
		int carry = 0, remainder = 0;
		ListNode *head = new ListNode(0);
		ListNode *n1 = l1, *n2 = l2, *current = head, *prev = NULL;
		bool isHead = true;

		while (n1) {
			sum = n1->val + n2->val + carry;
			carry = sum / 10;
			remainder = sum % 10;
			if (!isHead) {
				current = new ListNode(remainder);
				prev->next = current;
			} else {
				current->val = remainder;
				isHead = false;
			}

			prev = current;

			n1 = n1->next;
			n2 = n2->next;
		}

		while (n2) {
			sum = n2->val + carry;
			carry = sum / 10;
			remainder = sum % 10;
			current = new ListNode(remainder);
			prev->next = current;
			prev = current;
			n2 = n2->next;
		}

		if(carry! = 0){
			current = new ListNode(carry);
			prev->next = current;
		}

		return head;
	}

	int lenOfList(ListNode* head) {
		int len = 0;
		ListNode *n = head;
		while (n) {
			len++;
			n = n->next;
		}
		return len;
	}
};

