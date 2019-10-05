class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// 用unordered_set对nums1中的元素去重
		unordered_set<int> s1;
		for (auto e : nums1)
			s1.insert(e);

		// 用unordered_set对nums2中的元素去重
		unordered_set<int> s2;
		for (auto e : nums2)
			s2.insert(e);

		// 遍历s1，如果s1中某个元素在s2中出现过，即为交集
		vector<int> vRet;
		for (auto e : s1)
		{
			if (s2.find(e) != s2.end())
				vRet.push_back(e);
		}
		return vRet;
	}
};