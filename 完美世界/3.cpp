#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
	long long int N, K;
	cin >> N >> K;
	int key[49] = { 0,   0, 1, 1, 0, 1, 0, 0, 1,    1, 0, 0, 1, 0, 1, 1, 0,    1, 0, 0, 1, 0, 1, 1, 0,
					0, 1, 1, 0, 1, 0, 0, 1,    1, 0, 0, 1, 0, 1, 1, 0,    0, 1, 1, 0, 1, 0, 0, 1 };
	cout << key[K % 49] << endl;
	return 0;
}