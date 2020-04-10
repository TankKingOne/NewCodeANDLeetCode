#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		size_t row = text1.length();
		size_t col = text2.length();
		vector<vector<int>> dp;
		dp.resize(row + 1, vector<int>(col + 1));
		for (size_t i = 0; i <= row; ++i)
		{
			dp[i][0] = 0;
		}
		for (size_t j = 0; j <= col; ++j)
		{
			dp[0][j] = 0;
		}
		for (size_t i = 1; i <= row; ++i)
		{
			for (size_t j = 1; j <= col; ++j)
			{
				if (text1[i - 1] == text2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i - 1][j] > dp[i][j - 1] ? dp[i][j] = dp[i - 1][j] : dp[i][j] = dp[i][j - 1];
				}
			}
		}
		return dp[row][col];
	}
};

int main()
{
	Solution s;
	string text1 = "abcde", text2 = "ace";
	cout << s.longestCommonSubsequence(text1, text2);
	
	system("pause");
	return 0;
}