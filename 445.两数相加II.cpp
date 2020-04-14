#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1->val == 0)
			return l2;
		if (l2->val == 0)
			return l1;

		ListNode* tl1 = recerseList(l1);
		ListNode* tl2 = recerseList(l2);
		ListNode* ret = new ListNode(-1e7);
		ListNode* cur = ret;
		int carry = 0; // ½øÎ»
		while (tl1 && tl2) {
			int count = tl1->val + tl2->val + carry;
			carry = 0;
			if (count > 9) {
				carry = 1;
				count -= 10;
			}
			ListNode* newNode = new ListNode(count);
			cur->next = newNode;
			cur = cur->next;
			tl1 = tl1->next;
			tl2 = tl2->next;
		}
		while(tl1){
			int count = tl1->val + carry;
			carry = 0;
			if (count > 9) {
				carry = 1;
				count -= 10;
			}
			ListNode* newNode = new ListNode(count);
			cur->next = newNode;
			cur = cur->next;
			tl1 = tl1->next;
		}
		while (tl2) {
			int count = tl2->val + carry;
			carry = 0;
			if (count > 9) {
				carry = 1;
				count -= 10;
			}
			ListNode* newNode = new ListNode(count);
			cur->next = newNode;
			cur = cur->next;
			tl2 = tl2->next;
		}
		ListNode* temp = ret;
		ret = recerseList(ret->next);
		delete(temp);
		
		return ret;
	}
	ListNode* recerseList(ListNode* l) {
		ListNode* prev = NULL;
		ListNode* cur = l;
		ListNode* next = l->next;
		while(cur != NULL){
			cur->next = prev;
			prev = cur;
			cur = next;
			if (cur == NULL)
				break;
			next = cur->next;
		}
		return prev;
	}
};

int main()
{
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	l1.next = &l2;
	l2.next = &l3;

	ListNode l4(1);
	ListNode l5(2);
	ListNode l6(3);
	ListNode l7(4);
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;

	Solution s;
	ListNode* reet = s.addTwoNumbers(&l1, &l4);
	while (reet)
	{
		cout << reet->val << ' ';
		reet = reet->next;
	}
	system("pause");
	return 0;
}
