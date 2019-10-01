class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int count = 0;
		auto it = find(numbers.begin(), numbers.end(), numbers[numbers.size() / 2]);
		auto i = it;
		while (i != numbers.end())
		{
			if (*i == *it)
			{
				count++;
				i++;
			}
			else
				break;
		}
		if (count > numbers.size() / 2)
			return *it;
		else
			return 0;
	}
};