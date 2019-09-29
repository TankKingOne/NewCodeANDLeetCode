#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		
		ret.resize(numRows);
		
		if (numRows == 0)
			return ret;
		
		for (int i = 1; i <= numRows; ++i)
		{
			ret[i - 1].resize(i, 0);
			ret[i - 1][0] = 1;
			ret[i - 1][i - 1] = 1;
		}

		for(int i = 0; i < ret.size(); ++i)
			for (int j = 0; j < ret[i].size(); ++j)
			{
				if (ret[i][j] == 0)
					ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		return ret;
	}
};

int main()
{
	Solution s;
	int k;
	cin >> k;
	vector<vector<int>> ret = s.generate(k);
	system("pause");
	return 0;
}