#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) { //双指针滑动窗口
		int max = 0;
		map<char, int> hashmap;  //当前子串中各个字母出现的次数
		int n = s.size();
		for (int i = 0, j = 0; j < n; j++) {//当前判断是否重复的串为s[i..j]
			hashmap[s[j]]++;
			while (hashmap[s[j]] > 1) {
				hashmap[s[i++]]--;  //i指针右移
			}
			if (j - i + 1 > max)
				max = j - i + 1;
		}
		return max;
	}
};

int main()
{
	Solution s;
	string str("abcabcbb");
	cout << s.lengthOfLongestSubstring(str);
	system("pause");
	return 0;
}