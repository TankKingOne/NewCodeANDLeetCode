#include <iostream>
#include <cstdio>
int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;
	//��ǰ����쳲��������У�ֻ������6λ
	for (int i = 2; i <= 100000; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000; //��������ӣ�����ֻҪ����λ��Ӱ����һ�����Ľ��
	}
	//����������OJƽ̨��ʱ�ӿ�ʼ��ȡ���ݵ�trick��������ɿ������ںܶ���Ŀ��
	int n;
	while (std::cin >> n)
	{
		if (n < 29)
		{
			//쳲���������С��6λ
			printf("%d\n", fib[n]);
		}
		else
		{
			printf("%06d\n", fib[n]);
		}
	}
	return 0;
}