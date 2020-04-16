#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> ret(matrix);
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
			{
				ret[i][j] = ret[i][j] == 0 ? 0 : 10000;
			}
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
			{
				if (i >= 1)
				{
					ret[i][j] = min(ret[i][j], ret[i - 1][j] + 1);
				}
				if (j >= 1)
				{
					ret[i][j] = min(ret[i][j], ret[i][j - 1] + 1);
				}
			}
		for (int i = row - 1; i >= 0; --i)
			for (int j = col - 1; j >= 0; --j)
			{
				if (i < row - 1)
				{
					ret[i][j] = min(ret[i][j], ret[i + 1][j] + 1);
				}
				if (j < col - 1)
				{
					ret[i][j] = min(ret[i][j], ret[i][j + 1] + 1);
				}
			}
		return ret;
	}
};


//int main()
//{
//	Solution s;
//	vector<vector<int>> vv = { {0, 0, 0}, {0, 1, 0}, {1, 1, 1} };
//	vector<vector<int>> r = s.updateMatrix(vv);
//	for (auto e : r)
//	{
//		for (auto i : e)
//		{
//			cout << i;
//		}
//	}
//	system("pause");
//	return 0;
//}