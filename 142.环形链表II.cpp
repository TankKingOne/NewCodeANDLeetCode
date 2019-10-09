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
	ListNode* hasCycle(ListNode *head)
	{
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
				return fast;
		}
		return nullptr;
	}

	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr)
			return nullptr;

		ListNode* meet = hasCycle(head);
		if (meet == nullptr)
			return nullptr;

		while (1)
		{
			if (meet == head)
			{
				return meet;
			}
			else
			{
				meet = meet->next;
				head = head->next;
			}
		}
	}
};