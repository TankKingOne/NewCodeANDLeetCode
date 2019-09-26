class Solution {
public:
	string NumLetter[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if (digits.size() == 0)
			return ret;
		
		size_t i = 0;
		string str;
		_letterCombinations(digits, i, str, ret);
		return ret;
	}

	void _letterCombinations(string &digits, size_t i, const string &str, vector<string> &ret)
	{

		if (i == digits.length())
		{
			ret.push_back(str);
			return;
		}

		string letter = NumLetter[digits[i]-'0'];
		for (size_t j = 0; j < letter.length(); ++j)
		{
			_letterCombinations(digits, i + 1, str + letter[j], ret);
		}
	}
};