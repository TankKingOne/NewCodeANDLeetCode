class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> m1;
		for (auto e : nums1)
			m1[e]++;

		unordered_map<int, int> m2;
		for (auto e : nums2)
			m2[e]++;

		vector<int> ret;
		for (auto e : m1)
		{
			auto m2tmp = m2.find(e.first);
			if (m2tmp != m2.end())
			{
				int k = (m2tmp->second < e.second ? m2tmp->second : e.second);
				while (k--)
				{
					ret.push_back(e.first);
				}
			}
		}
		return ret;
	}
};