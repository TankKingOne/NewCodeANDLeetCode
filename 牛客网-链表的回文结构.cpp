/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/

// �ȿ��ٿռ临����������������Ƚ�,��Ҫ����O(n)�Ŀռ䣬������ĿҪ��
// ��ת�����벿�֣���Ƚ�
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
		// �ҵ��м�ڵ�
		ListNode* mid = findMid(A);
		ListNode* halflast = mid->next;
		// ��ת��벿��
		halflast = reverseNode(halflast);
		mid->next = nullptr;
		// �Ƚ�
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