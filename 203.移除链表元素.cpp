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
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr)
			return head;

		ListNode* cur = head;
		ListNode* prev = nullptr;
		ListNode* next = nullptr;

		while (cur)
		{

			if (cur->val == val)
			{
				next = cur->next;
				delete cur;
				cur = next;

				if (prev == nullptr)
				{
					head = next;
				}
				else
				{
					prev->next = next;
				}
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}

		}
		return head;
	}
};