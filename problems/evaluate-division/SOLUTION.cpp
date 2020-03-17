//struct Node {
//    double value;
//    Node* parent;
//    Node() : parent(this) {}
//    Node(double v) : value(v), parent(this) {}
//};
//
//class Solution {
//    unordered_map<string, Node*> m;
//
//    Node* find(Node* n) {
//        if (n->parent != n) {
//            n->parent = find(n->parent);
//        }
//        return n->parent;
//    }
//
//    void merge(Node* n1, Node* n2, double val) {
//        Node* p1 = find(n1);
//        Node* p2 = find(n2);
//        double ratio = n2->value * val / n1->value;
//        for (auto it : m) {
//            if (find(it.second) == p1) {
//                it.second->value *= ratio;
//            }
//        }
//        p1->parent = p2;
//    }
//public:
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        for (int i = 0; i < equations.size(); ++i) {
//            string a = equations[i][0];
//            string b = equations[i][1];
//            if (m.find(a) == m.end()) m[a] = new Node(values[i]);
//            if (m.find(b) == m.end()) m[b] = new Node(1.0);
//            merge(m[a], m[b], values[i]);
//        }
//        vector<double> res;
//        for (auto q : queries) {
//            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end() || find(m[q[0]]) != find(m[q[1]])) {
//                res.push_back(-1);
//            }
//            else {
//                res.push_back(m[q[0]]->value / m[q[1]]->value);
//            }
//        }
//        return res;
//    }
//};




struct DSU
{
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (data[y] < data[x]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }

    int size(int x) { return -data[root(x)]; }

    std::vector<int> data;
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int getIdx(string s, unordered_map<string, int>& um)
    {
        if (um.find(s) != um.end()) return um[s];
        um[s] = um.size();
        return um[s];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, int> um;
        vector<double> num(10000, 0);
        DSU dsu(num.size());
        for (int i = 0; i < equations.size(); i++)
        {
            int a = getIdx(equations[i][0], um);
            int b = getIdx(equations[i][1], um);
            num[a] = (num[a] == 0) ? values[i] : num[a];
            num[b] = (num[b] == 0) ? 1 : num[b];

            double ratio = num[b] * values[i] / num[a];
            for (auto& p : um)
            {
                if (dsu.same(p.second, a))
                {
                    num[p.second] *= ratio;
                }
            }
            dsu.unionSet(a, b);
        }

        vector<double> ans;
        for (auto& q : queries)
        {
            int a = getIdx(q[0], um);
            int b = getIdx(q[1], um);
            if (num[a] == 0 || num[b] == 0)
            {
                ans.push_back(-1.0);
                continue;
            }
            if (!dsu.same(a, b))
            {
                ans.push_back(-1.0);
                continue;
            }
            ans.push_back(num[a] / num[b]);
        }
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<double> _solution_run(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.calcEquation(equations, values, queries);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
