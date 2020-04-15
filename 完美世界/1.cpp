#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	vector<int> num;
	string str;
	getline(cin, str);
	const char *str1 = str.data();
	char str2[1000];
	strcpy(str2, str1);
	const char *sp = " ";
	char *p;
	p = strtok(str2, sp);
	while (p != NULL)
	{
		num.push_back(atoi(p));
		p = strtok(NULL, sp);
	}

	int begin = 0;
	int step = num.size()*0.25 + 1;
	while (begin <= num.size() - step)
	{
		if (num[begin] == num[begin + step])
		{
			cout << num[begin] << endl;
			break;
		}
		else
		{
			begin++;
		}
	}
	
	system("pause");
}