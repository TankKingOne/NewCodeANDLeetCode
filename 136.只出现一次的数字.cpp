//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		int ret = 0;
//		for (size_t i = 0; i < nums.size(); ++i)
//		{
//			ret ^= nums[i];
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<int> v = { 1,1,2,3,4,3,2 };
//	cout << s.singleNumber(v) << endl;
//	system("pause");
//	return 0;
//}