class Solution {
public:
	int Add(int num1, int num2) {
		while (num2 != 0) {
			int sum = num1 ^ num2; //�õ���Ӻ󲻰�����λ������
			int carray = (num1 & num2) << 1; //�õ�������ӵĽ�λ
			num1 = sum; //���������ӣ�ֱ����λΪ0
			num2 = carray;
		}
		return num1;
	}
};