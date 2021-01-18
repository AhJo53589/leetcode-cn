# `（中等）` [721.accounts-merge 账户合并](https://leetcode-cn.com/problems/accounts-merge/)

### 题目描述
<p>给定一个列表 <code>accounts</code>，每个元素 <code>accounts[i]</code>&nbsp;是一个字符串列表，其中第一个元素 <code>accounts[i][0]</code>&nbsp;是&nbsp;<em>名称 (name)</em>，其余元素是 <em>emails </em>表示该账户的邮箱地址。</p>

<p>现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。</p>

<p>合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
<b>输出：
</b>[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
<b>解释：</b>
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>accounts</code>的长度将在<code>[1，1000]</code>的范围内。</li>
	<li><code>accounts[i]</code>的长度将在<code>[1，10]</code>的范围内。</li>
	<li><code>accounts[i][j]</code>的长度将在<code>[1，30]</code>的范围内。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/accounts-merge/solution/accounts-merge-by-ikaruga-fprw/)

### 答题
``` C++
struct DSU {
    DSU(int n) : data(n, -1) {}

    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) {
            swap(x, y);
        }
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }

    vector<int> data;
}; 


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        unordered_map<string, int> mp;
        for (int i = 0; i < accounts.size(); i++) {
            int x = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                const auto& email = accounts[i][j];
                if (mp.find(email) != mp.end()) {
                    x = mp[email];
                    dsu.unionSet(x, i);
                }
                else {
                    mp[email] = x;
                }
            }
        }

        unordered_map<int, pair<string, set<string>>> temp;
        for (int i = 0; i < accounts.size(); i++) {
            int x = dsu.root(i);
            if (temp.find(x) == temp.end()) {
                temp[x] = {accounts[i][0], set<string>()};
            }
            for (int j = 1; j < accounts[i].size(); j++) {
                temp[x].second.insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for (auto& [k, p] : temp) {
            ans.push_back({p.first});
            for (auto& e : p.second) {
                ans.back().push_back(e);
            }
        }
        return ans;
    }
};
```




