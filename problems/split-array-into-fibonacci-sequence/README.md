# `（中等）` [842.split-array-into-fibonacci-sequence 将数组拆分成斐波那契序列](https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/)

### 题目描述
<p>给定一个数字字符串 <code>S</code>，比如 <code>S = "123456579"</code>，我们可以将它分成斐波那契式的序列 <code>[123, 456, 579]</code>。</p>

<p>形式上，斐波那契式序列是一个非负整数列表 <code>F</code>，且满足：</p>

<ul>
	<li><code>0 &lt;= F[i] &lt;= 2^31 - 1</code>，（也就是说，每个整数都符合 32 位有符号整数类型）；</li>
	<li><code>F.length &gt;= 3</code>；</li>
	<li>对于所有的<code>0 &lt;= i &lt; F.length - 2</code>，都有 <code>F[i] + F[i+1] = F[i+2]</code> 成立。</li>
</ul>

<p>另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。</p>

<p>返回从 <code>S</code> 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 <code>[]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>"123456579"
<strong>输出：</strong>[123,456,579]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入: </strong>"11235813"
<strong>输出: </strong>[1,1,2,3,5,8,13]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入: </strong>"112358130"
<strong>输出: </strong>[]
<strong>解释: </strong>这项任务无法完成。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>"0123"
<strong>输出：</strong>[]
<strong>解释：</strong>每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入: </strong>"1101111"
<strong>输出: </strong>[110, 1, 111]
<strong>解释: </strong>输出 [11,0,11,11] 也同样被接受。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= S.length&nbsp;&lt;= 200</code></li>
	<li>字符串 <code>S</code> 中只含有数字。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        backtrack(ans, S, 0);
        return ans;
    }

    bool backtrack(vector<int>& ans, string& s, int pos) {
        if (pos == s.size()) return ans.size() >= 3;
        long long val = 0;
        long long sum = (ans.size() < 2) ? -1 : (long long)ans[ans.size() - 2] + ans.back();
        for (int i = pos; i < s.size(); i++) {
            if (i > pos && s[pos] == '0') break;
            val = val * 10 + s[i] - '0';
            if (val > INT_MAX) break;
            if (sum != -1 && sum < val) break;
            if (sum == -1 || sum == val) {
                ans.push_back(val);
                if (backtrack(ans, s, i + 1)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
};
```




