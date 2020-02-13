
//////////////////////////////////////////////////////////////////////////
// 16ms
class Solution 
{
    bool ok;
    bool vis[10];
    int n;
    int num[26];
    vector<char> lead;

    void dfs(int p, int pp, int jin, vector<string>& words, string& result) {
        if (ok) return;
        if (p == n) {
            if (jin != 0) return;
            ok = true;/*
            for (auto &i:lead){
                if (num[i-'A']==0){
                    ok=false;
                    return;
                }
            }*/
            for (int i = 0; i < 26; ++i) {
                if (num[i] != -1) {
                    cout << char('A' + i) << "=" << num[i] << ' ';
                }
            }
            cout << endl;
            return;
        }
        int rl = jin, rr;
        for (int i = pp; i < words.size(); ++i) {
            if (words[i].length() <= p) continue;
            if (num[words[i][p] - 'A'] != -1) {
                rl += num[words[i][p] - 'A'];
            }
            else {
                for (int j = 0; j < 10; ++j) {
                    if (vis[j]) continue;
                    vis[j] = true;
                    rl += j;
                    num[words[i][p] - 'A'] = j;
                    dfs(p, i + 1, rl, words, result);
                    vis[j] = false;
                    rl -= j;
                    num[words[i][p] - 'A'] = -1;
                }
                return;
            }
        }
        if (result.length() <= p) {
            if (rl % 10 == 0) dfs(p + 1, 0, rl / 10, words, result);
        }
        else if (num[result[p] - 'A'] != -1) {
            rr = num[result[p] - 'A'];
            if (rr == rl % 10) dfs(p + 1, 0, rl / 10, words, result);
        }
        else {
            if (vis[rl % 10]) return;
            rr = rl % 10;
            vis[rr] = true;
            num[result[p] - 'A'] = rr;
            dfs(p + 1, 0, rl / 10, words, result);
            vis[rr] = false;
            num[result[p] - 'A'] = -1;
        }
    }

public:
    bool isSolvable(vector<string>& words, string& result) {
        memset(num, -1, sizeof(num));
        memset(vis, false, sizeof(vis));
        n = result.length();
        if (result.length() > 1) lead.push_back(result[0]);
        for (auto& e : words) {
            n = max(n, (int)e.length());
            reverse(e.begin(), e.end());
            if (e.length() > 1) lead.push_back(e[0]);
        }
        reverse(result.begin(), result.end());
        ok = false;
        dfs(0, 0, 0, words, result);
        return ok;
    }
};



//////////////////////////////////////////////////////////////////////////
// ��Ա������ 52ms

//class Solution 
//{
//public:
//	bool check(int lv)
//	{
//		int sum = inc;
//		for (int i = 0; i < 26; i++)
//		{
//			sum += equation[lv][i] * en[i];
//		}
//		inc = sum / 10;
//		return (sum % 10 == 0);
//	}
//
//	void dfs(int lv, int idx)
//	{
//		if (ans) return;
//		if (idx == charsLen[lv])
//		{
//			//{	// ��� log
//			//	for (size_t i = 0; i < 26; i++)
//			//	{
//			//		if (en[i] == -1) continue;
//			//		char c = i + 'A';
//			//		cout << c << ": " << en[i] << "\t";
//			//	}
//			//	int temp = inc;
//			//	string str = (check(lv)) ? "check success!" : "check failed";
//			//	cout << str << endl;
//			//	inc = temp;
//			//}
//
//			if (!check(lv)) return; // ��鷽��
//			ans = (lv == 7);
//			if (ans) return;
//
//			dfs(lv + 1, 0); // ���ɹ������׶�
//		}
//
//		if (idx < 0 || idx >= charsLen[lv]) return;
//		char c = chars[lv][idx];
//		for (int n = 0; n < 10; n++)
//		{
//			if (ne[n]) continue;
//			if (n == 0 && zeroFlag[c - 'A']) continue;
//
//			en[c - 'A'] = n; // ��ĸ��Ӧ������
//			ne[n] = true; // �����Ƿ�used
//			int tempInc = inc;
//
//			dfs(lv, idx + 1);
//
//			en[c - 'A'] = -1; // ���ݣ���״̬�Ļ���
//			ne[n] = false;
//			inc = tempInc;
//		}
//	}
//
//	bool isSolvable(vector<string>& words, string result)
//	{
//		memset(equation, 0, sizeof(equation));
//		memset(chars, 0, sizeof(chars));
//		memset(charsLen, 0, sizeof(charsLen));
//		memset(zeroFlag, false, sizeof(zeroFlag));
//		memset(en, -1, sizeof(en));
//		memset(ne, false, sizeof(ne));
//		inc = 0;
//		ans = false;
//
//		// �������ݵ�����ʽ
//		words.push_back(result);
//		for (size_t j = 0; j < words.size(); j++)
//		{
//			auto w = words[j];
//			zeroFlag[w[0] - 'A'] = true;
//			size_t d = 0;
//			for (size_t i = w.size() - 1; i < w.size(); i--)
//			{
//				equation[d++][w[i] - 'A'] += (j == words.size() - 1) ? -1 : 1;
//			}
//		}
//
//		// ����ÿ���׶ε���ĸ
//		unordered_set<char> us;
//		for (size_t d = 0; d < 8; d++)
//		{
//			for (int i = 0; i < 26; i++)
//			{
//				if (equation[d][i] == 0) continue;
//				char c = i + 'A';
//				if (us.count(c) != 0) continue;
//				chars[d][charsLen[d]++] = c;
//				us.insert(c);
//			}
//		}
//
//		dfs(0, 0);
//		return ans;
//	}
//
//private:
//	int equation[8][26];
//	char chars[8][6];
//	int charsLen[8];
//	bool zeroFlag[26];
//	int en[26];
//	bool ne[10];
//	int inc;
//	bool ans;
//};



//////////////////////////////////////////////////////////////////////////
// 52ms

// ��鵱ǰ�׶η����Ƿ�������Լ����½�λinc
bool check(vector<vector<int>>& eq, int lv, vector<int>& en, int& inc)
{
	auto& cur_eq = eq[lv];
	int sum = inc;
	for (int i = 0; i < cur_eq.size(); i++)
	{
		sum += cur_eq[i] * en[i];
	}
	inc = sum / 10;
	return (sum % 10 == 0);
}

void dfs(vector<vector<int>>& eq, vector<vector<char>>& chars, int lv, int idx, int inc, vector<char>& ne, vector<int>& en, vector<bool>& zeroFlag, bool& ans)
{
	if (ans) return;
	if (idx == chars[lv].size())
	{
		//{	// ��� log
		//	for (size_t i = 0; i < 26; i++)
		//	{
		//		if (en[i] == -1) continue;
		//		char c = i + 'A';
		//		cout << c << ": " << en[i] << "\t";
		//	}
		//	int temp = inc;
		//	string str = (check(eq, lv, en, temp)) ? "check success!" : "check failed";
		//	cout << str << endl;
		//}

		if (!check(eq, lv, en, inc)) return; // ��鷽��
		ans = (lv == 7);
		if (ans) return;

		dfs(eq, chars, lv + 1, 0, inc, ne, en, zeroFlag, ans); // ���ɹ������׶�
	}

	if (idx < 0 || idx >= chars[lv].size()) return;
	char c = chars[lv][idx];
	for (int n = 0; n < 10; n++)
	{
		if (ne[n] != 'a') continue;
		if (n == 0 && zeroFlag[c - 'A']) continue;

		en[c - 'A'] = n; // ��ĸ��Ӧ������
		ne[n] = c; // ���ֶ�Ӧ����ĸ�������൱�������Ƿ�used��
		int tempInc = inc;

		dfs(eq, chars, lv, idx + 1, inc, ne, en, zeroFlag, ans);

		en[c - 'A'] = -1; // ���ݣ���״̬�Ļ���
		ne[n] = 'a';
		inc = tempInc;
	}
}

bool isSolvable(vector<string>& words, string result)
{
	vector<char> ne(10, 'a');
	vector<int> en(26, -1);
	vector<bool> zeroFlag(26, false);
	vector<vector<int>> equation(8, vector<int>(26, 0));
	vector<vector<char>> chars(8, vector<char>());

	words.push_back(result);
	for (size_t j = 0; j < words.size(); j++)
	{
		auto w = words[j];
		zeroFlag[w[0] - 'A'] = true;
		size_t d = 0;
		for (size_t i = w.size() - 1; i < w.size(); i--)
		{
			equation[d++][w[i] - 'A'] += (j == words.size() - 1) ? -1 : 1;
		}
	}
	unordered_set<char> us;
	for (size_t d = 0; d < 8; d++)
	{
		for (int i = 0; i < equation[d].size(); i++)
		{
			if (equation[d][i] == 0) continue;
			char c = i + 'A';
			if (us.count(c) != 0) continue;
			chars[d].push_back(c);
			us.insert(c);
		}
	}

	bool ans = false;
	dfs(equation, chars, 0, 0, 0, ne, en, zeroFlag, ans);
	return ans;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<string>& words, string result)
{
	Solution sln;
	return sln.isSolvable(words,result);
	//return isSolvable(words, result);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

