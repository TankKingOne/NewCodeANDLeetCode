#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		list<vector<int>> list;
		vector<vector<int>> ret;
		for (size_t i = 0; i < intervals.size(); ++i)
		{
			list.push_back(intervals[i]);
		}
		while (list.size() > 1)
		{
			vector<int> first = list.front();
			list.pop_front();
			vector<int> second = list.front();
			list.pop_front();
			if (first[1] >= second[1])
				list.push_front(first);
			else if (first[0] <= second[0] && first[1] >= second[0])
			{
				vector<int> temp = { first[0], second[1] };
				list.push_front(temp);
			}
			else
			{
				ret.push_back(first);
				list.push_front(second);
			}
		}
		ret.push_back(list.front());
		return ret;
	}
};


int main()
{
	Solution s;
	vector<vector<int>> k = { {1,3},{2,6},{8,10},{15,18} };
	vector<vector<int>> ret = s.merge(k);
	for (auto e : ret)
	{
		for (auto i : e)
		{
			cout << i << ' ';
		}
	}
	system("pause");
	return 0;
}