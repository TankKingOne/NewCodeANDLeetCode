class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> us;
		for (auto e : nums)
		{
			if (us.find(e) == us.end())
			{
				us.insert(e);
			}
			else
				return true;
		}
		return false;
	}
};