# `（困难）` [301.remove-invalid-parentheses 删除无效的括号](https://leetcode-cn.com/problems/remove-invalid-parentheses/)

### 题目描述
<p>给你一个由若干括号和字母组成的字符串 <code>s</code> ，删除最小数量的无效括号，使得输入的字符串有效。</p>

<p>返回所有可能的结果。答案可以按 <strong>任意顺序</strong> 返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "()())()"
<strong>输出：</strong>["(())()","()()()"]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "(a)())()"
<strong>输出：</strong>["(a())()","(a)()()"]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = ")("
<strong>输出：</strong>[""]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 25</code></li>
	<li><code>s</code> 由小写英文字母以及括号 <code>'('</code> 和 <code>')'</code> 组成</li>
	<li><code>s</code> 中至多含 <code>20</code> 个括号</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/301-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {	
        s = filterOut(s);

        set<string> ans;
        vector<int> use(s.size(), 1);

        for (int k = 0; k < s.size(); k++) {
            for (int i = 0; i < s.size(); i++) {
                use[i] = (i >= k) ? 1 : 0;
            }

            do {
                if (valid(s, use)) {
                    string a;
                    for (size_t i = 0; i < s.size(); i++) {
                        if (!use[i]) continue;
                        a += s[i];
                    }
                    ans.insert(a);

                    k = s.size();
                }
            } while (next_permutation(use.begin(), use.end()));
        }
        if (ans.empty()) return { "" };
        return vector<string>(ans.begin(), ans.end());
    }

    string filterOut(string& s) {
        vector<bool> filter(s.size(), false);
        int left = 0;
        int right = count(s.begin(), s.end(), ')');
        for (int i = 0; i < s.size(); i++) {
            left += (s[i] == '(');
            right -= (s[i] == ')');
            
            filter[i] = (s[i] == '(' && right == 0) || (s[i] == ')' && left == 0);
        }

        string ns;
        for (int i = 0; i < s.size(); i++) {
            if (filter[i]) continue;
            ns += s[i];
        }
        return ns;
    }

    bool valid(string& s, vector<int>& use) {
        int st = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (use[i] == 0) continue;
            st += (s[i] == '(');
            st -= (s[i] == ')');
            if (st < 0) return false;
        }
        return (st == 0);
    }
};

```




