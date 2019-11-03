///*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};*/
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x) {
//		// write code here
//		if (pHead == nullptr)
//			return pHead;
//
//		ListNode* littleHead = new ListNode(0);
//		ListNode* bigHead = new ListNode(0);
//		ListNode* littleTail = littleHead;
//		ListNode* bigTail = bigHead;
//
//		while (pHead)
//		{
//			if (pHead->val < x)
//			{
//				littleTail->next = pHead;
//				littleTail = littleTail->next;
//			}
//			else
//			{
//				bigTail->next = pHead;
//				bigTail = bigTail->next;
//			}
//			pHead = pHead->next;
//		}
//		bigTail->next = nullptr;
//		littleTail->next = bigHead->next;
//		return littleHead->next;
//	}
//};