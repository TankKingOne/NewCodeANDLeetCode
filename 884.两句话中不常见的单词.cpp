class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		unordered_map<string, int> m;
		PartionWord(A, m);
		PartionWord(B, m);

		vector<string> vRet;
		for (auto& e : m)
		{
			if (1 == e.second)
				vRet.push_back(e.first);
		}
		return vRet;
	}

	void PartionWord(const string& str, unordered_map<string, int>& m)
	{
		string strWord;
		int start = 0, last = 0;
		do
		{
			last = str.find(' ', start);
			strWord = str.substr(start, last - start);
			m[strWord]++;
			start = last + 1;
		} while (-1 != last);
	}
};