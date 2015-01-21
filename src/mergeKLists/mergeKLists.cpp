/* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **/

#include<iostream>
#include<queue>
#include<functional>
#include <cassert>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Item {
public:
	int element;
	int listNo;

	Item() {
	}

	Item(int p1, int p2) {
		element = p1;
		listNo = p2;
	}

	void dump() {
		cout << element << "->" << listNo << endl;
	}

	friend bool operator <(const Item& lhs, const Item& rhs) {
		return lhs.element < rhs.element;
	}

	friend bool operator >(const Item& lhs, const Item& rhs) {
		return lhs.element > rhs.element;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		int size = lists.size();

		priority_queue<Item, vector<Item>, greater<Item> > test;
		ListNode *head, *currentNode;

		for (int i = 0; i < size; i++) {
			if (lists[i] != NULL) {
				test.push(Item(lists[i]->val, i));
			}
		}

		Item currentItem;
		int currentIndex;

		if (!test.empty()) {
			currentItem = test.top();
			currentIndex = currentItem.listNo;
			head = currentNode = lists[currentIndex];
			test.pop();
			if (lists[currentIndex]->next != NULL) {
				lists[currentIndex] = lists[currentIndex]->next;
				test.push(Item(lists[currentIndex]->val, currentIndex));
			}

			while (!test.empty()) {
				currentItem = test.top();
				currentIndex = currentItem.listNo;

				currentNode->next = lists[currentIndex];
				currentNode = lists[currentIndex];

				test.pop();

				if (lists[currentIndex]->next != NULL) {
					lists[currentIndex] = lists[currentIndex]->next;
					test.push(Item(lists[currentIndex]->val, currentIndex));
				}

			}

			return head;
		} else
			return NULL;
	}
};

