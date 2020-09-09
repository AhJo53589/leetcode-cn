# `（中等）` [1578.minimum-deletion-cost-to-avoid-repeating-letters 避免重复字母的最小删除成本](https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/)

[contest](https://leetcode-cn.com/contest/weekly-contest-205/problems/minimum-deletion-cost-to-avoid-repeating-letters/)

### 题目描述
<p>给你一个字符串 <code>s</code> 和一个整数数组 <code>cost</code> ，其中 <code>cost[i]</code> 是从 <code>s</code> 中删除字符 <code>i</code> 的代价。</p>

<p>返回使字符串任意相邻两个字母不相同的最小删除成本。</p>

<p>请注意，删除一个字符后，删除其他字符的成本不会改变。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abaac", cost = [1,2,3,4,5]
<strong>输出：</strong>3
<strong>解释：</strong>删除字母 "a" 的成本为 3，然后得到 "abac"（字符串中相邻两个字母不相同）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abc", cost = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>无需删除任何字母，因为字符串中不存在相邻两个字母相同的情况。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "aabaa", cost = [1,2,3,4,1]
<strong>输出：</strong>2
<strong>解释：</strong>删除第一个和最后一个字母，得到字符串 ("aba") 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s.length == cost.length</code></li>
	<li><code>1 &lt;= s.length, cost.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= cost[i] &lt;=&nbsp;10^4</code></li>
	<li><code>s</code> 中只含有小写英文字母</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/solution/minimum-deletion-cost-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        for (int i = 0; i < s.size();) {
            for (int j = i; j < s.size(); j++) {
                if (j != s.size() - 1 && s[i] == s[j + 1]) continue;
                if (i != j) {
                    ans += del(s, i, j, cost);  
                }               
                i = j + 1;
            }
        }
        return ans;
    }
    
    int del(string& s, int l, int r, vector<int>& cost) {
        int sum = 0;
        int m = cost[l];
        for (int i = l; i <= r; i++) {
            sum += cost[i];
            m = max(m, cost[i]);
        }
        return sum - m;
    }
};
```




