#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		size_t row = word1.length();
		size_t col = word2.length();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1));
		for (size_t i = 0; i <= row; ++i)
		{
			dp[i][0] = i;
		}
		for (size_t i = 0; i <= col; ++i)
		{
			dp[0][i] = i;
		}
		for (size_t i = 1; i <= row; ++i)
		{
			for (size_t j = 1; j <= col; ++j)
			{
				int exchange = 0;
				if (word1[i - 1] != word2[j - 1])
				{
					exchange = 1;
				}
				int temp = min(dp[i - 1][j - 1] + exchange, dp[i - 1][j] + 1);
				dp[i][j] = min(temp, dp[i][j - 1] + 1);
			}
		}
		return dp[row][col];
	}
};


int main()
{
	Solution s;
	string word1 = "horse";
	string word2 = "ros";
	cout << s.minDistance(word1, word2);

	system("pause");
	return 0;
}