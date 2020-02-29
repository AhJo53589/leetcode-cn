# `（困难）` [32.longest-valid-parentheses 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)

### 题目描述
<p>给定一个只包含 <code>'('</code>&nbsp;和 <code>')'</code>&nbsp;的字符串，找出最长的包含有效括号的子串的长度。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> "(()"
<strong>输出:</strong> 2
<strong>解释:</strong> 最长有效括号子串为 <code>"()"</code>
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "<code>)()())</code>"
<strong>输出:</strong> 4
<strong>解释:</strong> 最长有效括号子串为 <code>"()()"</code>
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/32-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int longestValidParentheses(string s)
    {
        pair<char, char> k = { '(',')' };
        s.insert(s.begin(), k.second);
        s.insert(s.begin(), k.second);
        vector<int> dp(s.size(), 0);
        int ans = 0;
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] == k.first)
            {
                dp[i] = 0;
            }
            else
            {
                if (s[i - 1] == k.first)
                {
                    dp[i] = dp[i - 2] + 2;
                }
                else if (s[i - dp[i - 1] - 1] == k.first)
                {
                    dp[i] = dp[i - dp[i - 1] - 2] + 2 + dp[i - 1];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```


### 其它
``` C++
class Solution {
public:
    int longestValidParentheses(string s) 
    {
        pair<char, char> k = { '(',')' };
        map<char, int> dic;
        dic[k.first] = -1;
        dic[k.second] = -2;

        int ans = 0;
        stack<int> st;
        for (auto& c : s)
        {
            if (c == k.first)
            {
                st.push(dic[c]);
                continue;
            }

            int temp = 0;
            while (!st.empty() && st.top() != dic[k.first] && st.top() != dic[k.second])
            {
                temp += st.top();
                st.pop();
            }
            if (st.empty() || st.top() != dic[k.first])
            {
                st.push(temp);
                st.push(dic[c]);
                continue;
            }

            st.pop();
            temp += 2;
            while (!st.empty() && st.top() != dic[k.first] && st.top() != dic[k.second])
            {
                temp += st.top();
                st.pop();
            }
            ans = max(ans, temp);
            st.push(temp);
        }
        return ans;
    }
};

```


