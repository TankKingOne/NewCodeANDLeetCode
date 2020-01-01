class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		vector<int> mxL(n, 0);//��¼iλ������ֵ
		vector<int> mxR(n, 0);//��¼iλ�Ҳ����ֵ
		int ma = INT_MIN;
		for (int i = 0; i < n; i++) {//���
			if (i == 0)
				mxL[i] = A[i];
			else
				mxL[i] = max(A[i], mxL[i - 1]); // �� i λ�������ֵ���� i - 1 λ���ֵ�� i ��ֵ�Ľ�
			��ֵ
		}
		for (int i = n - 1; i >= 0; i--) {//�Ҳ�
			if (i == n - 1)
				mxR[i] = A[i];
			else
				mxR[i] = max(A[i], mxR[i + 1]);
		}
		// ������������Ϊ [2,7,3,1,1]
		// mxL �е�ֵΪ: [2,7,7,7,7]
		// mxR �е�ֵΪ: [7,7,3,1,1]
		int res = INT_MIN;
		// ��������ѭ����������������ֵ����.
		for (int i = 0; i < n - 1; i++) {//���
			res = max(res, abs(mxL[i] - mxR[i + 1]));
		}
		return res;
	}
};