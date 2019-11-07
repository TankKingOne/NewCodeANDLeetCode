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
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr)
			return head;

		ListNode* fast = head;
		ListNode* slow = head;

		while (fast)
		{
			if (fast->next && fast->next->next)
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			else
			{
				break;
			}
		}

		if (fast->next)
			return slow->next;
		else
			return slow;
	}
};