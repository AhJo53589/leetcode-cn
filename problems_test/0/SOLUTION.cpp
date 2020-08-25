
// ����������A��B�����ֲ����ֱ��� + 12�� - 12�� + 7�� - 7�� + 5�� - 5��
// A�������ɴβ��������B ����������2����A��B��Ҫ�����任���̣������еĲ������о���һ��·����Ҳ�������ٵĲ������� ��
// ����˼·�ʹ���

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
	vector<int> minMove(int A, int B) {

    }

	void init() {
		queue<pair<int, vector<int>>> que;
		for (auto p : op) {
			que.push(pair<int, vector<int>>(p, { p }));
		}
		while (!que.empty()) {
            for (int len = que.size() - 1; len >= 0; len--) {
				auto [t, vec] = que.front();
				que.pop();
				
				if (t == 0) continue;
				if (t >= data.size() || -t >= data.size()) continue;
				if (t > 0 && !data[t].empty()) continue;
				if (t < 0 && !data[-t].empty()) continue;
				if (t < 0) {
					turn(vec);
					t *= -1;
				}
				data[t] = vec;

                for (auto p : op) {
					vec.push_back(p);
                    que.push(pair<int, vector<int>>(t + p, vec));
					vec.pop_back();
                }
            }
		}
	}

	void turn(vector<int>& vec) {
        for (auto& v : vec) {
            v *= -1;
        }
	}

private:
	vector<int> op = { 12,7,5,-12,-7,-5 };
	vector<vector<int>> data = vector<vector<int>>(5 * 7 * 12, vector<int>());
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(vector<int> nums)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.minMove(nums[0], nums[1]);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
