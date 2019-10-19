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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode* head = l1;
		if (l1->val > l2->val)
		{
			head = l2;
			l2 = l2->next;
		}
		else
		{
			l1 = l1->next;
		}

		ListNode* tail = head;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				tail->next = l1;
				tail = tail->next;
				l1 = l1->next;
			}
			else
			{
				tail->next = l2;
				tail = tail->next;
				l2 = l2->next;
			}
		}
		while (l1)
		{
			tail->next = l1;
			tail = tail->next;
			l1 = l1->next;
		}
		while (l2)
		{
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}

		return head;
	}
};