class MinStack {
	stack<int> nums;
	stack<int> minnums;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		nums.push(x);
		if (minnums.empty() || x <= minnums.top())
			minnums.push(x);
	}

	void pop() {
		if (nums.top() == minnums.top())
			minnums.pop();
		nums.pop();
	}

	int top() {
		return nums.top();
	}

	int getMin() {
		return minnums.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */