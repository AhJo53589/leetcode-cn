


//////////////////////////////////////////////////////////////////////////
//int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
//{
//	int ans = 0;
//	unordered_map<string, int> cnts;
//	vector<int> chars(26, 0);
//	vector<int> tmpChars(26, 0);
//	int curLetters = 0;
//	string curStr = "";
//
//	for (size_t i = 0; i < minSize - 1; i++)
//	{
//		curStr += s[i];
//		curLetters += (chars[s[i] - 'a']++ == 0);
//	}
//	//cout << "curStr: " << curStr << endl;
//
//	for (size_t i = minSize - 1; i < s.size(); i++)
//	{
//		tmpChars = chars;
//		int tmpLetters = curLetters;
//		string tmpStr = curStr;
//		for (size_t j = 0; j < maxSize - minSize + 1; j++)
//		{
//			int k = i + j;
//			if (k >= s.size()) break;
//			tmpStr += s[k];
//			tmpLetters += (tmpChars[s[k] - 'a']++ == 0);
//
//			if (tmpLetters > maxLetters) break;
//			cnts[tmpStr]++;
//			//cout << tmpStr << ":\t" << cnts[tmpStr] << endl;
//			ans = max(ans, cnts[tmpStr]);
//		}
//
//		if (curStr.size() == 0) continue;
//		curLetters -= (--chars[curStr[0] - 'a'] == 0);
//		curStr.erase(curStr.begin());
//
//		curStr += s[i];
//		curLetters += (chars[s[i] - 'a']++ == 0);
//	}
//	return ans;
//}

//////////////////////////////////////////////////////////////////////////
int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
{
	int ans = 0;
	unordered_map<string, int> cnts;
	vector<int> chars(26, 0);
	int curLetters = 0;
	string curStr = "";

	for (size_t i = 0; i < s.size(); i++)
	{
		curStr += s[i];
		curLetters += (chars[s[i] - 'a']++ == 0);
		if (curStr.size() < minSize) continue;

		if (curLetters <= maxLetters)
		{
			cnts[curStr]++;
			ans = max(ans, cnts[curStr]);
		}

		curLetters -= (--chars[curStr[0] - 'a'] == 0);
		curStr.erase(curStr.begin());
	}

	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(string s, int maxLetters, int minSize, int maxSize)
{
	//cout << s << ", maxLetters = " << maxLetters << ", minSize = " << minSize << ", maxSize = " << maxSize << endl;
	return maxFreq(s,maxLetters,minSize,maxSize);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/maximum-number-of-occurrences-of-a-substring/tests.txt";
}

