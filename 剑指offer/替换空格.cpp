#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0)
			return;
		int count = 0, newlength = 0, oldlength = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
				count++;

			oldlength++;
			i++;
		}
		newlength = oldlength + count * 2;

		if (newlength > length)
			return;

		int end = newlength;
		int begin = oldlength;

		while (oldlength >= 0)
		{
			if (str[begin] != ' ')
			{
				str[end--] = str[begin--];
			}
			else
			{
				str[end--] = '0';
				str[end--] = '2';
				str[end--] = '%';
				begin--;
			}
			oldlength--;
		}
	}
};

int main()
{
	Solution s;
	char str[30] = "hello ll nn ll.";
	s.replaceSpace(str, 30);
	cout << str << endl;
	system("pause");
}