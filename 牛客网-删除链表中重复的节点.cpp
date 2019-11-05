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
				while (next)// 找第一个不相等的节点
				{
					if (next->val != cur->val)
						break;

					next = next->next;
				}
				// 删除cur~next之间的节点
				while (cur != next)
				{
					ListNode* tmp = cur;
					cur = cur->next;
					delete tmp;
				}
				// 重新连接
				if (prev == nullptr) // 删除的是头结点
				{
					pHead = next;
				}
				else  // 删除的是中间节点
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