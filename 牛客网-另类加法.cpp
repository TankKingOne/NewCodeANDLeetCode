class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, carry = 0;
		while (B != 0) {
			//对应位的和
			sum = A ^ B;
			//对应位和的进位，既然是进位，就要整体左移一位
			carry = (A&B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};