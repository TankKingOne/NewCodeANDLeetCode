#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct player
{
	int w;
	int h;
};
bool com_w(player p1, player p2)
{
	//按照体重从小到大排序
	if (p1.w != p2.w)
		return p1.w <= p2.w;
	//在体重相等的条件下，身高高的在前（在上）
	else
		return p1.h > p2.h;
}
int main(void)
{
	int N;
	int h;
	int w;
	int index;
	vector<player> p;
	while (cin >> N)
	{
		p.clear();
		// 处理数据
		for (int i = 0; i < N; i++)
		{
			player pt;
			cin >> index >> w >> h;
			pt.w = w;
			pt.h = h;
			p.push_back(pt);
		}
		sort(p.begin(), p.end(), com_w);
		//按照身高求最大上升子序列(此处为核心代码)
		//关于最大上升子序列问题的讲解, 参看 https://www.cnblogs.com/wxjor/p/5524447.html
		int dp2[N + 1];
		int max = 0;
		dp2[0] = 1;
		for (int i = 1; i < N; i++)
		{
			dp2[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (p[j].h <= p[i].h && dp2[j] + 1 > dp2[i])
					dp2[i] = dp2[j] + 1;
			}
		}
		// 找出 dp2 中最大的数据, 即为最终结果
		for (int i = 0; i < N; i++)
			if (max < dp2[i])
				max = dp2[i];
		cout << max << endl;
	}
	system("pause");
	return 0;
}