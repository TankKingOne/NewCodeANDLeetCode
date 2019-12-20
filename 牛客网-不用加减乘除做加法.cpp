class Solution {
public:
	int Add(int num1, int num2) {
		while (num2 != 0) {
			int sum = num1 ^ num2; //得到相加后不包含进位的数据
			int carray = (num1 & num2) << 1; //得到两数相加的进位
			num1 = sum; //两个结果相加，直到进位为0
			num2 = carray;
		}
		return num1;
	}
};