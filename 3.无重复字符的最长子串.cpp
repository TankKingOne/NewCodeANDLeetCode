#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) { //˫ָ�뻬������
		int max = 0;
		map<char, int> hashmap;  //��ǰ�Ӵ��и�����ĸ���ֵĴ���
		int n = s.size();
		for (int i = 0, j = 0; j < n; j++) {//��ǰ�ж��Ƿ��ظ��Ĵ�Ϊs[i..j]
			hashmap[s[j]]++;
			while (hashmap[s[j]] > 1) {
				hashmap[s[i++]]--;  //iָ������
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