class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
	{
		stack<int> tmp;
		size_t i = 0, j = 0;
		while (i < pushV.size())
		{
			tmp.push(pushV[i]);
			++i;

			while (j < popV.size())
			{
				if (tmp.top() == popV[j])
				{
					++j;
					tmp.pop();
				}
				else
					break;
			}
		}
		return tmp.empty();
	}
};
