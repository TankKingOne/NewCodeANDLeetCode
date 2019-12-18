#include <iostream>
#include <string>
int numRoot(int num) {
	int nroot = 0;
	while (num > 0) {
		/*每次只获取个位数字---个位数+十位数*/
		nroot += num % 10;
		num /= 10;
	}
	while (nroot > 9) {
		nroot = numRoot(nroot);
	}
	return nroot;
}
int main()
{
	std::string origin;
	while (std::cin >> origin) {
		int sum = 0;
		//先将每一位进行相加得到总和，防止数字过大
		for (int i = 0; i < origin.length(); i++) {
			sum += origin[i] - '0';
		}
		//对总和求树根
		std::cout << numRoot(sum) << std::endl;
	}
	return 0;
}