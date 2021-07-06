#include<vector>
#include<iostream>
using namespace std;

//Definition of ListNode
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// 1. Divide and Conquer
// class Solution {
// public:
//     /**
//      * @param lists: a list of ListNode
//      * @return: The head of one sorted list.
//      */
//     ListNode *mergeKLists(vector<ListNode *> &lists) {
//         // write your code here
// 		// find current list
// 		int i = 0;
// 		ListNode* currentList = NULL;
// 		for (; i < lists.size(); ++i) {
// 			if (lists[i] != NULL) {
// 				currentList = lists[i];
// 				break;
// 			}
// 		}
// 		// find next list and merge
// 		for (int j = i+1; j < lists.size(); ++j) {
// 			ListNode *nextList = lists[j];
// 			if (nextList != NULL) {
// 				currentList = mergeTwoLists(currentList, nextList);
// 			}
// 		}
// 		return currentList;
//     }

// 	ListNode* mergeTwoLists(ListNode* listA, ListNode* listB) {
// 		ListNode* current = NULL;
// 		ListNode* compared = NULL;
// 		ListNode* head = NULL;
// 		if (listA->val <= listB->val) {
// 			current = listA;
// 			compared = listB;
// 		} else {
// 			current = listB;
// 			compared = listA;
// 		}
// 		head = current;
// 		// current val shall always be smaller or equal than compared val
// 		// insert compared to current
// 		while (compared != NULL)
// 		{
// 			if (current->next == NULL || current->next->val > compared->val) {
// 				auto oldComparedNext = compared->next;
// 				auto oldCurrentNext = current->next;
// 				current->next = compared;
// 				compared->next = oldCurrentNext;
// 				current = compared;
// 				compared = oldComparedNext;	
// 			} else {
// 				current = current->next;
// 			}
// 		}
// 		return head;
// 	}
// };

#include<queue>

class Solution {
public:
	/**
      * @param lists: a list of ListNode
      * @return: The head of one sorted list.
      */
     ListNode *mergeKLists(vector<ListNode *> &lists) {
		 auto cmp = [](ListNode* l, ListNode* r){ return l->val > r->val;};
		 priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
		 for (auto l : lists) {
			 if (l) {
				 q.push(l);
			 }
		 }
		 while (!q.empty()) {
			 cout<<q.top()->val<<" ";
			 q.pop();
		 }
		 return nullptr;
	 }

};

int main() {
	Solution s;
	ListNode* a = new ListNode(2);
	ListNode* a1 = new ListNode(4);
	a->next = a1;
	ListNode* b = new ListNode(-1);
	vector<ListNode*> vec{NULL, b, a};
	ListNode* result = s.mergeKLists(vec);
	// for (ListNode *cur = result; cur != NULL; cur = cur->next) {
	// 	cout<<cur->val<<" ";
	// }
}