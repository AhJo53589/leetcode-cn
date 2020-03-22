class Solution2 {
public:
    int maxSizeSlicesInner(vector<int>& slices) {
        vector<int> dp_prev(slices);
        vector<int> dp_next(slices.size(), 0);
        int n = slices.size() / 3 + 1;
        for (int r = 1; r < n; ++r) {
            int prev_max = 0;
            for (int c = 0; c < slices.size(); ++c) {
                if (c >= 2) prev_max = max(dp_prev[c - 2], prev_max);
                dp_next[c] = slices[c] + prev_max;
            }
            swap(dp_prev, dp_next);
        }
        return *max_element(dp_prev.begin(), dp_prev.end());
    }

    int maxSizeSlices(vector<int>& slices) {
        vector<int> v1(slices.begin() + 1, slices.end());    // 去除第一块披萨的情形
        vector<int> v2(slices.begin(), prev(slices.end()));  // 去除最后一块披萨的情形
        return max(maxSizeSlicesInner(v1), maxSizeSlicesInner(v2));  // 取两种情形的最大值
    }
};


//////////////////////////////////////////////////////////////////////////
struct Node {
    int value, l, r;
};

vector<Node> a; // 基于vector实现双向链表

struct Id {
    int id;

    bool operator<(const Id& that) const {
        return a[id].value < a[that.id].value;
    }
};

void del(int i) {
    a[a[i].l].r = a[i].r;
    a[a[i].r].l = a[i].l;
}

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;

        // 初始化双向链表
        a.clear();
        for (int i = 0; i < n; ++i)
            a.emplace_back(Node{ slices[i], (i - 1 + n) % n, (i + 1) % n });
        priority_queue<Id> pq;
        vector<bool> used(n); // 标记某一序号是否能够选取
        int idx = 0;
        for (int i = 0; i < n; ++i)
            pq.push(Id{ i }); // 优先队列初始化
        int cnt = 0, ans = 0;
        while (cnt < k) {
            int id = pq.top().id;
            pq.pop();
            if (!used[id]) { // 当前序号可用
                cnt++;
                ans += a[id].value;
                // 标记前后序号
                auto pre = a[id].l;
                auto nxt = a[id].r;
                used[pre] = true;
                used[nxt] = true;
                // 更新当前序号的值为反悔值
                a[id].value = a[pre].value + a[nxt].value - a[id].value;
                // 当前序号重新入队
                pq.push(Id{ id });
                // 删除前后序号（更新双向链表）
                del(pre);
                del(nxt);
            }
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& slices)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution2 sln;
	return sln.maxSizeSlices(slices);
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
