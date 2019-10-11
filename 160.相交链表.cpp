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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr)
			return nullptr;

		int countA = 0;
		int countB = 0;
		ListNode* curA = headA;
		ListNode* curB = headB;
		ListNode* fast;
		ListNode* slow = headA;

		while (curA)
		{
			countA++;
			curA = curA->next;
		}
		while (curB)
		{
			countB++;
			curB = curB->next;
		}
		fast = countA > countB ? headA : headB;
		if (fast == headA)
			slow = headB;

		int k = abs(countA - countB);
		while (k--)
		{
			fast = fast->next;
		}
		while (fast)
		{
			if (fast == slow)
				return fast;
			fast = fast->next;
			slow = slow->next;
		}
		return nullptr;
	}
};