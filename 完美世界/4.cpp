#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <list>

using namespace std;



int main()
{
	list<int> num;
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
	int n;
	cin >> n;
	int k = num.size() - n + 1;
	for (auto e  = num.begin(); e != num.end(); ++e)
	{
		if (k > 0)
		{
			k--;
		}
		if (k == 0)
		{
			num.erase(e);
			break;
		}
	}
	
	for (auto e : num)
	{
		cout << e << ' ';
	}
	system("pause");
}