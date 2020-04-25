# `（简单）` [949.largest-time-for-given-digits 给定数字能组成的最大时间](https://leetcode-cn.com/problems/largest-time-for-given-digits/)

### 题目描述
<p>给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。</p>

<p>最小的 24 小时制时间是&nbsp;00:00，而最大的是&nbsp;23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。</p>

<p>以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[1,2,3,4]
<strong>输出：</strong>"23:41"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[5,5,5,5]
<strong>输出：</strong>""
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>A.length == 4</code></li>
	<li><code>0 <= A[i] <= 9</code></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/largest-time-for-given-digits/solution/largest-time-for-given-digits-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> limit = { 2, 9, 5, 9 };
        vector<int> cnt(10, 0);
        for (auto n : A) {
            cnt[n]++;
        }
        
        vector<int> ans;
        if (!dfs(cnt, limit, ans)) return "";
        return to_string(ans[0]) + to_string(ans[1]) + ":" + to_string(ans[2]) + to_string(ans[3]);
    }

    bool dfs(vector<int>& cnt, vector<int>& limit, vector<int>& ans) {
        if (ans.size() == 4) return true;
        for (int i = limit[ans.size()]; i >= 0; i--) {
            i = (ans.size() == 1 && ans[0] == 2 && i == 9) ? 3 : i;
            
            if (cnt[i] == 0) continue;
            cnt[i]--;
            ans.push_back(i);
            if (dfs(cnt, limit, ans)) return true;
            ans.pop_back();
            cnt[i]++;
        }
        return false;
    }
};
```




