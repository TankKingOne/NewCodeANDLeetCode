#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		vector<int> begin;
		vector<int> size;
		int count = 0;
		string ret;
		if (s[0] != ' ')
		{
			begin.push_back(0);
		}
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == ' ' && i+1 < s.length() && s[i + 1] != ' ')
			{
				begin.push_back(i + 1);
			}
			if (s[i] != ' ')
			{
				count++;
				if (s[i + 1] == ' ')
				{
					size.push_back(count);
					count = 0;
				}
			}
		}
		size.push_back(count);
		int k = 0;

		for (k = begin.size() - 1; k >= 0; --k)
		{
			ret += s.substr(begin[k], size[k]);
			if(k != 0)
				ret += ' ';
		}
		
		return ret;
	}
};

//int main()
//{
//	Solution s;
//	string str("  hello world!  ");
//	cout << s.reverseWords(str);
//	system("pause");
//	return 0;
//}