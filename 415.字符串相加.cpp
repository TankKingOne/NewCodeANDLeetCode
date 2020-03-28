class Solution {
public:
	string addStrings(string num1, string num2)
	{
		//使 num1 和 num2 长度相同（短的前面补0）
		while (num1.size() < num2.size())
		{
			num1 = '0' + num1;
		}
		while (num1.size() > num2.size())
		{
			num2 = '0' + num2;
		}
		string val;
		int res = 0;
		for (int i = num1.size() - 1; i >= 0; i--)
		{
			int temp = num1[i] - '0' + num2[i] - '0'; //记录两个 数字 和
			res = res + temp;
			val = to_string(res % 10) + val;          //将 int 转换成 string ，并 "前插"
			res /= 10;                                //记录进位
		}
		if (res != 0)
			val = to_string(res) + val;
		return val;
	}
};