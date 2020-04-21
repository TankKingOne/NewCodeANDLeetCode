#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 滑动窗口
// 1. 不断右移 right 指针来扩大滑动窗口，使其包含 k 个奇数；
// 2. 若当前滑动窗口包含了 k 个奇数，则如下「计算当前窗口的优美子数组个数」：
// 统计第 1 个奇数左边的偶数个数 leftEvenCnt。 这 leftEvenCnt 个偶数都可以作为「优美子数组」的起点，因此起点的选择有 leftEvenCnt + 1 种。
// 统计第 k 个奇数右边的偶数个数 rightEvenCnt 。 这 rightEvenCnt 个偶数都可以作为「优美子数组」的终点，因此终点的选择有 rightEvenCnt + 1 种。
// 因此「优美子数组」左右起点的选择组合数为(leftEvenCnt + 1) * (rightEvenCnt + 1)。


class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int left = 0, right = 0, oddCount = 0, res = 0;
		while (right < nums.size())
		{
			if ((nums[right++] & 1) == 1)
				oddCount++;

			if (oddCount == k)
			{
				int temp = right;
				while (temp < nums.size() && (nums[temp] & 1) == 0)
				{
					temp++;
				}
				int rightEvenCount = temp - right;
				int leftEvenCount = 0;
				while ((nums[left] & 1) == 0)
				{
					leftEvenCount++;
					left++;
				}
				res += (leftEvenCount + 1) * (rightEvenCount + 1);
				left++;
				oddCount--;
				right = temp;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1, 1, 2, 1, 1 };

	cout << s.numberOfSubarrays(nums, 3);
	system("pause");
	return 0;
}