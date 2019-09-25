//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//class MyQueue {
//public:
//	stack<int> s1, s2;
//	/** Initialize your data structure here. */
//	MyQueue() {
//
//	}
//
//	/** Push element x to the back of queue. */
//	void push(int x) {
//		s1.push(x);
//
//	}
//
//	/** Removes the element from in front of queue and returns that element. */
//	int pop() {
//		while (!s1.empty())
//		{
//			s2.push(s1.top());
//			s1.pop();
//		}
//		int ret = s2.top();
//		s2.pop();
//		while (!s2.empty())
//		{
//			s1.push(s2.top());
//			s2.pop();
//		}
//		return ret;
//	} 
//
//	/** Get the front element. */
//	int peek() {
//		while (!s1.empty())
//		{
//			s2.push(s1.top());
//			s1.pop();
//		}
//		int ret = s2.top();
//		while (!s2.empty())
//		{
//			s1.push(s2.top());
//			s2.pop();
//		}
//		return ret;
//	}
//
//	/** Returns whether the queue is empty. */
//	bool empty() {
//		return (s1.empty());
//	}
//};
//
///**
// * Your MyQueue object will be instantiated and called as such:
// * MyQueue* obj = new MyQueue();
// * obj->push(x);
// * int param_2 = obj->pop();
// * int param_3 = obj->peek();
// * bool param_4 = obj->empty();
// */
//
//int main()
//{
//	MyQueue mq;
//	mq.push(1);
//	mq.push(2);
//	mq.push(3);
//	mq.push(4);
//	mq.push(5);
//	cout << mq.pop() << endl;
//	cout << mq.peek() << endl;
//	cout << mq.empty() << endl;
//
//	system("pause");
//	return 0;
//}