
//////////////////////////////////////////////////////////////////////////

class STNode {
public:
    long long val = 0L;
    long long left = 0L;
    long long right = 0L;
    STNode* leftNode = nullptr;
    STNode* rightNode = nullptr;
    long long lazyAdd = 0L;

    STNode(long long _left, long long _right, long long _val = 0) : left(_left), right(_right), val(_val), lazyAdd(-1L) {
    }

    long long getMid() {
        return left + (right - left >> 1);
    }

    STNode* getLeftNode() {
        if (leftNode == nullptr) {
            leftNode = new STNode(left, getMid(), val);
        }
        return leftNode;
    }

    STNode* getRightNode() {
        if (rightNode == nullptr) {
            rightNode = new STNode(getMid() + 1, right, val);
        }
        return rightNode;
    }
};

class SegTree {
public:
    SegTree(long long left, long long right) {
        root = new STNode(left, right);
    }

    SegTree(long long left, long long right, long long val) {
        root = new STNode(left, right, val);
    }

    long long query(long long left, long long right) {
        return query(root, left, right);
    }

    long long query(STNode* node, long long left, long long right) {
        if (right < node->left || left > node->right) return 0;
        if (left <= node->left && node->right <= right) return node->val;

        pushDown(node);
        return query(node->getLeftNode(), left, right) + query(node->getRightNode(), left, right);
    }

    void add(long long left, long long right, long long val) {
        add(root, left, right, val);
    }

    void add(STNode* node, long long left, long long right, long long val) {
        if (left > node->right || node->left > right) return;
        if (left <= node->left && node->right <= right) {
            node->val = val;
            node->lazyAdd = val;
            return;
        }

        pushDown(node);

        long long mid = node->getMid();
        if (right <= mid) {
            add(node->getLeftNode(), left, right, val);
        }
        else if (left > mid) {
            add(node->getRightNode(), left, right, val);
        }
        else {
            add(node->getLeftNode(), left, mid, val);
            add(node->getRightNode(), mid + 1, right, val);
        }
        pushUp(node);
    }

    void pushUp(STNode* node) {
        node->val = node->getLeftNode()->val + node->getRightNode()->val;
    }

    void pushDown(STNode* node) {
        if (node->lazyAdd == -1L) return;

        if (node->leftNode != nullptr) {
            node->leftNode->val = node->lazyAdd;
            node->leftNode->lazyAdd = node->lazyAdd;
        }
        if (node->rightNode != nullptr) {
            node->rightNode->val = node->lazyAdd;
            node->rightNode->lazyAdd = node->lazyAdd;
        }
        node->lazyAdd = -1L;
    }

private:
    STNode * root;
};

class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        int ans = 0;

        vector<int> list;
        inOrder(root, list);

        SegTree st(list.front(), list.back());
        for (auto n : list) {
            st.add(n, n, 0);
        }
        for (auto& op : ops) {
            st.add(op[1], op[2], op[0]);
        }
        for (auto n : list) {
            ans += st.query(n, n);
        }

        return ans;
    }

    void inOrder(TreeNode* root, vector<int>& list) {
        if (root == nullptr) return;
        inOrder(root->left, list);
        list.push_back(root->val);
        inOrder(root->right, list);
    }
};


//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root, vector<vector<int>>& ops)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.getNumber(root, ops);
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
