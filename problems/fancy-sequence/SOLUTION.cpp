
//////////////////////////////////////////////////////////////////////////
class Fancy {
private:
    vector<int> v, a, b;
    static constexpr int mod = 1000000007;

public:
    Fancy() {
        a.push_back(1);
        b.push_back(0);
    }

    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y & 1) {
                ret = (long long)ret * cur % mod;
            }
            cur = (long long)cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }

    int inv(int x) {
        return quickmul(x, mod - 2);
    }

    void append(int val) {
        v.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }

    void addAll(int inc) {
        if (v.empty()) return;
        b.back() += inc;
    }

    void multAll(int m) {
        if (v.empty()) return;
        a.back() = (long long)(a.back()) * m % mod;
        b.back() = (long long)(b.back()) * m % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size()) return -1;
        // printf("should = %d, %d %d, %d\n", a[idx], b[idx], a.back(), b.back());
        // back() vs idx
        int areal = inv(a[idx]);
        int breal = (long long)b[idx] * areal % mod;
        areal = (long long)areal * a.back() % mod;
        breal = ((b.back() - (long long)breal * a.back() % mod + mod) % mod + mod) % mod;
        // printf("real = %d %d\n", areal, breal);
        int ans = ((long long)areal * v[idx] % mod + breal) % mod;
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

//////////////////////////////////////////////////////////////////////////
//int _solution_run(int)
//{
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<string> sp = tc.get<vector<string>>();
	vector<string> ans;

	Fancy *obj = nullptr;
	for (auto i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "Fancy")
		{
			obj = new Fancy();
			ans.push_back("null");
		}
		else if (sf[i] == "append")
		{
			TestCases stc(sp[i]);
			int val = stc.get<int>();
			obj->append(val);
			ans.push_back("null");
		}
		else if (sf[i] == "addAll")
		{
			TestCases stc(sp[i]);
			int inc = stc.get<int>();
			obj->addAll(inc);
			ans.push_back("null");
		}
		else if (sf[i] == "multAll")
		{
			TestCases stc(sp[i]);
			int m = stc.get<int>();
			obj->multAll(m);
			ans.push_back("null");
		}
		else if (sf[i] == "getIndex")
		{
			TestCases stc(sp[i]);
			int idx = stc.get<int>();
			int r = obj->getIndex(idx);
			ans.push_back(convert<string>(r));
		}
	}
	delete obj;

	return convert<string>(ans);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
