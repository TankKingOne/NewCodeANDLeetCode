class Solution {
public:
	bool isValid(string s) {
		stack<char> sc;
		size_t i = 0;
		if (s[0] == ')' || s[i] == ']' || s[i] == '}' || s.length() % 2 != 0)
			return false;
		while (i < s.length())
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				sc.push(s[i]);

			if (s[i] == ')')
			{
				while (!sc.empty())
				{
					if (sc.top() != '(')
						return false;
					else
					{
						sc.pop();
						break;
					}
				}
			}

			if (s[i] == ']')
			{
				while (!sc.empty())
				{
					if (sc.top() != '[')
						return false;
					else
					{
						sc.pop();
						break;
					}
				}
			}

			if (s[i] == '}')
			{
				while (!sc.empty())
				{
					if (sc.top() != '{')
						return false;
					else
					{
						sc.pop();
						break;
					}
				}
			}
			++i;
		}
		if (sc.empty() && i == s.length())
			return true;
		return false;
	}
};