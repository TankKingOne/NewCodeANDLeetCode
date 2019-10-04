//class Solution {
//public:
//	int repeatedNTimes(vector<int>& A) {
//		size_t N = A.size() / 2;
//		unordered_map<int, int> m;
//		for (auto e : A)
//		{
//			m[e]++;
//		}
//		for (auto& e : m)
//		{
//			if (e.second == N)
//				return e.first;
//		}
//		return 0;
//	}
//};