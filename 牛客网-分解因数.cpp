#include <cstdio>
#include <cmath>
#include <iostream>
int main()
{
	unsigned int n;
	while (std::cin >> n)
	{
		printf("%d =", n); //输出90 =
		for (unsigned i = 2; i <= std::sqrt(n); i++)
		{
			while (n % i == 0 && n != i) //反复除同一个数，直到除不尽，排除刚好是该数的n次方的情况
			{
				printf(" %u *", i); //第一次打印 2 *,第二次打印两个 3 *
				n /= i; //能整除就修改n的值
			}
		}
		printf(" %d\n", n); //跳出后，n已经是处理过的一个质数，就是最后一个质因数：5
	}
	return 0;
}