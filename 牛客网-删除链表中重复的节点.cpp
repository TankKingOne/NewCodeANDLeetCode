/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		ListNode* prev = nullptr;
		ListNode* cur = pHead;
		ListNode* next = pHead->next;

		while (next)
		{
			if (cur->val == next->val)
			{
				next = next->next;
				while (next)// �ҵ�һ������ȵĽڵ�
				{
					if (next->val != cur->val)
						break;

					next = next->next;
				}
				// ɾ��cur~next֮��Ľڵ�
				while (cur != next)
				{
					ListNode* tmp = cur;
					cur = cur->next;
					delete tmp;
				}
				// ��������
				if (prev == nullptr) // ɾ������ͷ���
				{
					pHead = next;
				}
				else  // ɾ�������м�ڵ�
				{
					prev->next = next;
				}
				if (next)
					next = next->next;
			}
			else
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
		}
		return pHead;
	}
};