#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string str1, str2;
	string str3;
	cin >> n;
	cin >> str1 >> str2;
	long long int count[27] = { 0 };
	long long int countStr1[27] = { 0 };
	long long int countStr2[27] = { 0 };
	for (int i = 0; i < str1.length(); ++i)
	{
		countStr1[str1[i] - 'a']++;
	}
	for (int i = 0; i < str2.length(); ++i)
	{
		countStr2[str2[i] - 'a']++;
	}

	for (int i = 3; i <= n; ++i)
	{
		for (int j = 0; j < 27; ++j)
		{
			count[j] = countStr1[j] + countStr2[j];
			countStr1[j] = countStr2[j];
			countStr2[j] = count[j];
		}
	}
	for (int j = 0; j < 27; ++j)
	{
		if (count[j] != 0)
		{
			printf("%c:%d\n", 'a' + j, count[j]);
		}
	}

	system("pause");
	return 0;
}