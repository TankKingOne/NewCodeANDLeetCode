class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, carry = 0;
		while (B != 0) {
			//��Ӧλ�ĺ�
			sum = A ^ B;
			//��Ӧλ�͵Ľ�λ����Ȼ�ǽ�λ����Ҫ��������һλ
			carry = (A&B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};