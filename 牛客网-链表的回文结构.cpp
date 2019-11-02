/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/

// 先开辟空间复制链表，逆置链表，后比较,需要开辟O(n)的空间，不符题目要求
// 逆转链表后半部分，后比较
class PalindromeList {
public:
	ListNode* reverseNode(ListNode* head)
	{
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next = nullptr;
		while (cur)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
	ListNode* findMid(ListNode* head)
	{
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
	bool chkPalindrome(ListNode* A) {
		// 找到中间节点
		ListNode* mid = findMid(A);
		ListNode* halflast = mid->next;
		// 逆转后半部分
		halflast = reverseNode(halflast);
		mid->next = nullptr;
		// 比较
		ListNode* halfbefore = A;
		while (halfbefore && halflast)
		{
			if (halfbefore->val != halflast->val)
			{
				return false;
			}
			halfbefore = halfbefore->next;
			halflast = halflast->next;
		}
		return true;
	}
};