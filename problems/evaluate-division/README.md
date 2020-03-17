# `（中等）` [399.evaluate-division 除法求值](https://leetcode-cn.com/problems/evaluate-division/)

### 题目描述
<p>给出方程式&nbsp;<code>A / B = k</code>, 其中&nbsp;<code>A</code> 和&nbsp;<code>B</code> 均为代表字符串的变量，&nbsp;<code>k</code> 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回&nbsp;<code>-1.0</code>。</p>
<p><strong>示例 :</strong><br>
给定&nbsp;<code>a / b = 2.0, b / c = 3.0</code><br>
问题: <code> a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?&nbsp;</code><br>
返回&nbsp;<code>[6.0, 0.5, -1.0, 1.0, -1.0 ]</code></p>

<p>输入为: <code> vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries</code>(方程式，方程式结果，问题方程式)，&nbsp;其中&nbsp;<code>equations.size() == values.size()</code>，即方程式的长度与方程式结果长度相等（程式与结果一一对应），并且结果值均为正数。以上为方程式的描述。&nbsp;返回<code>vector<double></code>类型。</p>

<p>基于上述例子，输入如下：</p>
<pre>equations(方程式) = [ ["a", "b"], ["b", "c"] ],
values(方程式结果) = [2.0, 3.0],
queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
</pre>

<p>输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。</p>

---
### 思路
```

```



### 答题
``` C++
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

```



### 其它

更简洁的版本

```C++
struct Node {
    double value;
    Node* parent;
    Node() : parent(this) {}
    Node(double v) : value(v), parent(this) {}
};

class Solution {
    unordered_map<string, Node*> m;

    Node* find(Node* n) {
        if (n->parent != n) {
            n->parent = find(n->parent);
        }
        return n->parent;
    }
   
    void merge(Node* n1, Node* n2, double val) {
        Node* p1 = find(n1);
        Node* p2 = find(n2);
        double ratio = n2->value * val / n1->value;
        for (auto it : m) {
            if (find(it.second) == p1) {
                it.second->value *= ratio;
            }
        } 
        p1->parent = p2;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            if (m.find(a) == m.end()) m[a] = new Node(values[i]);
            if (m.find(b) == m.end()) m[b] = new Node(1.0);
            merge(m[a], m[b], values[i]);
        }
        vector<double> res;
        for (auto q : queries) {
            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end() || find(m[q[0]]) != find(m[q[1]])) {
                res.push_back(-1);
            } else {
                res.push_back(m[q[0]]->value / m[q[1]]->value);
            }
        }
        return res;
    }
};
```

