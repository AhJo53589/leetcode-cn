//////////////////////////////////////////////////////////////////////////
class SegTree {
private:
    int n;
    vector<int> segnode;

private:
    void update_(int id, int l, int r, int x) {
        if (l > x || r < x) {
            return;
        }
        ++segnode[id];
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        update_(id * 2 + 1, l, mid, x);
        update_(id * 2 + 2, mid + 1, r, x);
    }

    int query_(int id, int l, int r, int ql, int qr) const {
        if (l > qr || r < ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return segnode[id];
        }
        int mid = (l + r) >> 1;
        return query_(id * 2 + 1, l, mid, ql, qr) + query_(id * 2 + 2, mid + 1, r, ql, qr);
    }

public:
    SegTree(int _n) : n(_n), segnode(_n * 4) {}

    void update(int x) {
        update_(0, 1, n, x);
    }

    int query(int left, int right) const {
        return query_(0, 1, n, left, right);
    }
};

class Solution3 {
private:
    static constexpr int mod = 1000000007;

public:
    int createSortedArray(vector<int>& instructions) {
        int ub = *max_element(instructions.begin(), instructions.end());
        SegTree tree(ub);
        long long ans = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int x = instructions[i];
            int smaller = tree.query(1, x - 1);
            int larger = tree.query(x + 1, ub);
            ans += min(smaller, larger);
            tree.update(x);
        }
        return ans % mod;
    }
};


//////////////////////////////////////////////////////////////////////////
class BIT {
private:
    int n;
    vector<int> tree;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x) {
        return x & (-x);
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }

    int query(int x) const {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class Solution2 {
private:
    static constexpr int mod = 1000000007;

public:
    int createSortedArray(vector<int>& instructions) {
        int ub = *max_element(instructions.begin(), instructions.end());
        BIT bit(ub);
        long long ans = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int x = instructions[i];
            int smaller = bit.query(x - 1);
            int larger = i - bit.query(x);
            ans += min(smaller, larger);
            bit.update(x);
        }
        return ans % mod;
    }
};

//////////////////////////////////////////////////////////////////////////
class BalancedTree {
private:
    struct BalancedNode {
        int val;
        int seed;
        int count;
        int size;
        BalancedNode* left;
        BalancedNode* right;

        BalancedNode(int _val, int _seed) : val(_val), seed(_seed), count(1), size(1), left(nullptr), right(nullptr) {}

        BalancedNode* left_rotate() {
            int prev_size = size;
            int curr_size = (left ? left->size : 0) + (right->left ? right->left->size : 0) + count;
            BalancedNode* root = right;
            right = root->left;
            root->left = this;
            root->size = prev_size;
            size = curr_size;
            return root;
        }

        BalancedNode* right_rotate() {
            int prev_size = size;
            int curr_size = (right ? right->size : 0) + (left->right ? left->right->size : 0) + count;
            BalancedNode* root = left;
            left = root->right;
            root->right = this;
            root->size = prev_size;
            size = curr_size;
            return root;
        }
    };

private:
    BalancedNode* root;
    int size;
    mt19937 gen;
    uniform_int_distribution<int> dis;

private:
    BalancedNode* insert_(BalancedNode* node, int x) {
        if (!node) {
            return new BalancedNode(x, dis(gen));
        }
        ++node->size;
        if (x < node->val) {
            node->left = insert_(node->left, x);
            if (node->left->seed > node->seed) {
                node = node->right_rotate();
            }
        }
        else if (x > node->val) {
            node->right = insert_(node->right, x);
            if (node->right->seed > node->seed) {
                node = node->left_rotate();
            }
        }
        else {
            ++node->count;
        }
        return node;
    }

public:
    BalancedTree() : root(nullptr), size(0), gen(random_device{}()), dis(INT_MIN, INT_MAX) {}

    int get_size() const {
        return size;
    }

    void insert(int x) {
        ++size;
        root = insert_(root, x);
    }

    int lower_bound(int x) const {
        BalancedNode* node = root;
        int ans = INT_MAX;
        while (node) {
            if (x == node->val) {
                return x;
            }
            if (x < node->val) {
                ans = node->val;
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        return ans;
    }

    int upper_bound(int x) const {
        BalancedNode* node = root;
        int ans = INT_MAX;
        while (node) {
            if (x < node->val) {
                ans = node->val;
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        return ans;
    }

    pair<int, int> rank(int x) const {
        BalancedNode* node = root;
        int ans = 0;
        while (node) {
            if (x < node->val) {
                node = node->left;
            }
            else {
                ans += (node->left ? node->left->size : 0) + node->count;
                if (x == node->val) {
                    return { ans - node->count + 1, ans };
                }
                node = node->right;
            }
        }
        return { INT_MIN, INT_MAX };
    }
};

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int createSortedArray(vector<int>& instructions) {
        BalancedTree treap;
        long long ans = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            int x = instructions[i];
            int lb = treap.lower_bound(x);
            int smaller = (lb == INT_MAX ? i : treap.rank(lb).first - 1);
            int rb = treap.upper_bound(x);
            int larger = (rb == INT_MAX ? 0 : i - treap.rank(rb).first + 1);
            ans += min(smaller, larger);
            treap.insert(x);
        }
        return ans % mod;
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& instructions)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	//printVectorT(instructions);
	Solution sln;
	return sln.createSortedArray(instructions);
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
