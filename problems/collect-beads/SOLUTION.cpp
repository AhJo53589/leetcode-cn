


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	int s;
	vector<vector<int>> ret;
	int solve(int L, int R, int target) {
		// trace(L, R, target);
		if (target != -1 && !(target >= L && target < R)) cout << "..." << endl;
		if (L + 1 == R) return L;
		int mid = (L + R) / 2;
		if (target == -1) {
			if (s >= mid && R - mid > mid - L) ++mid;
			// trace(L, R, mid, s);
			if (s >= mid) {
				int pos = solve(mid, R, -1);
				solve(L, mid, pos - (R - mid));
				ret.push_back({ pos, 0 });
				return pos - (R - mid);
			}
			else {
				int pos = solve(L, mid, -1);
				solve(mid, R, pos + (mid - L));
				ret.push_back({ pos, 1 });
				return pos + (mid - L);
			}
		}
		else {
			if (target >= mid && R - mid > mid - L) ++mid;
			if (target >= mid) {
				int pos = solve(L, mid, target - (mid - L));
				solve(mid, R, target);
				ret.push_back({ pos, 1 });
			}
			else {
				solve(L, mid, target);
				int pos = solve(mid, R, target + (R - mid));
				ret.push_back({ pos, 0 });
			}
			return target;
		}
		return -1;
	}
	vector<vector<int>> collectBeads(int n, int s) {
		this->s = s;
		ret.clear();
		solve(0, n, -1);
		return ret;
	}
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int n, int s)
{
	Solution sln;
	return sln.collectBeads(n,s);
}

//#define USE_SOLUTION_CUSTOM
//vector<vector<int>> _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

