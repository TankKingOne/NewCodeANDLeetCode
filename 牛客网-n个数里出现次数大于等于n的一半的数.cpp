#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int n;
	vector <int> vec;
	while (cin >> n)
		vec.push_back(n);
	int count = 1;
	int temp = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] == temp)
			count++;
		else
			count--;
		if (count == 0)
		{
		temp = vec[i];
		count++;
		}
	}
	cout << temp << endl;
	return 0;
}