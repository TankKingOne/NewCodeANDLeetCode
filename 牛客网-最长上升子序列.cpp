#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		// �����û����������
		vector<int> height(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}
		// f��������״̬ת�Ʒ��̵Ľ����f[i]��ʾ��height[i]��β�������������������Ԫ�صĸ���
		vector<int> f(n, 1);
		int result = 1;
		// �������е�����һ��һ������
		for (int i = 1; i < n; i++) {
			// ��0��ʼͳ�Ƶ�iλ�ã�����������г���
			for (int j = 0; j < i; j++) {
				if (height[i] > height[j]) {
					f[i] = max(f[i], f[j] + 1);
				}
			}
			// ��ȡ��0��iλ�õ�������г���
			result = max(result, f[i]);
		}
		cout << result << endl;
	}
}