
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int mod = 1e9 + 7;

        sort(inventory.rbegin(), inventory.rend());
        int low = 0;
        int high = INT_MAX;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(inventory, orders, mid)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        long long ans = 0;
        for (int i = 0; i < inventory.size() && orders != 0; i++) {
            long long cnt = min(inventory[i] - low, orders);
            if (cnt < 0) break;
            orders -= cnt;

            long long a = inventory[i];
            long long b = inventory[i] - cnt + 1;
            long long sum = (a + b) * cnt / 2;
            ans += sum;
            ans %= mod;
        }
        ans += (long long)orders * (long long)low;
        ans %= mod;
        return ans;
    }

    bool check(vector<int>& inventory, int orders, int target) {
        long long cnt = 0;
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i] < target) break;
            cnt += inventory[i] - target;
        }
        return cnt >= orders;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& inventory, int orders)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    printVectorT(inventory);
    cout << orders << endl;
    Solution sln;
    return sln.maxProfit(inventory, orders);
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
