# `（困难）` [5359.maximum-performance-of-a-team 最大的团队表现值](https://leetcode-cn.com/problems/maximum-performance-of-a-team/)

[contest](https://leetcode-cn.com/contest/weekly-contest-180/problems/maximum-performance-of-a-team/)

### 题目描述
<p>公司有编号为 <code>1</code>&nbsp;到 <code>n</code>&nbsp;的 <code>n</code>&nbsp;个工程师，给你两个数组 <code>speed</code>&nbsp;和 <code>efficiency</code>&nbsp;，其中 <code>speed[i]</code>&nbsp;和 <code>efficiency[i]</code>&nbsp;分别代表第 <code>i</code>&nbsp;位工程师的速度和效率。请你返回由最多&nbsp;<code>k</code>&nbsp;个工程师组成的&nbsp;<strong>​​​​​​最大团队表现值</strong>&nbsp;，由于答案可能很大，请你返回结果对 10^9 + 7 取余后的结果。</p>

<p><strong>团队表现值</strong>&nbsp;的定义为：一个团队中「所有工程师速度的和」乘以他们「效率值中的最小值」。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
<strong>输出：</strong>60
<strong>解释：</strong>
我们选择工程师 2（speed=10 且 efficiency=4）和工程师 5（speed=5 且 efficiency=7）。他们的团队表现值为 performance = (10 + 5) * min(4, 7) = 60 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
<strong>输出：</strong>68
<strong>解释：
</strong>此示例与第一个示例相同，除了 k = 3 。我们可以选择工程师 1 ，工程师 2 和工程师 5 得到最大的团队表现值。表现值为 performance = (2 + 10 + 5) * min(5, 4, 7) = 68 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
<strong>输出：</strong>72
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>speed.length == n</code></li>
	<li><code>efficiency.length == n</code></li>
	<li><code>1 &lt;= speed[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= efficiency[i] &lt;= 10^8</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-performance-of-a-team/solution/5359-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        const int mod = 1000000007;

        vector<vector<int>> es;
        for (int i = 0; i < efficiency.size(); i++)
        {
            es.push_back({ efficiency[i], speed[i] });
        }
        sort(es.rbegin(), es.rend());

        long long ans = 0;
        long long sum = 0;
        long long eff = INT_MAX;
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < es.size(); i++)
        {
            eff = es[i][0];
            sum += es[i][1];
            que.push(es[i][1]);
            if (--k < 0)
            {
                sum -= que.top();
                que.pop();
            }
            ans = max(ans, sum * eff);
        }
        return ans % mod;
    }
};
```




