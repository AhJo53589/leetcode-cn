# `（中等）` [5369.count-number-of-teams 统计作战单位数](https://leetcode-cn.com/problems/count-number-of-teams/)

[contest](https://leetcode-cn.com/contest/weekly-contest-182/problems/count-number-of-teams/)

### 题目描述
<p>&nbsp;<code>n</code> 名士兵站成一排。每个士兵都有一个 <strong>独一无二</strong> 的评分 <code>rating</code> 。</p>

<p>每 <strong>3</strong> 个士兵可以组成一个作战单位，分组规则如下：</p>

<ul>
	<li>从队伍中选出下标分别为 <code>i</code>、<code>j</code>、<code>k</code> 的 3 名士兵，他们的评分分别为 <code>rating[i]</code>、<code>rating[j]</code>、<code>rating[k]</code></li>
	<li>作战单位需满足： <code>rating[i] &lt; rating[j] &lt; rating[k]</code> 或者 <code>rating[i] &gt; rating[j] &gt; rating[k]</code> ，其中&nbsp; <code>0&nbsp;&lt;= i &lt;&nbsp;j &lt;&nbsp;k &lt;&nbsp;n</code></li>
</ul>

<p>请你返回按上述条件可以组建的作战单位数量。每个士兵都可以是多个作战单位的一部分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>rating = [2,5,3,4,1]
<strong>输出：</strong>3
<strong>解释：</strong>我们可以组建三个作战单位 (2,3,4)、(5,4,1)、(5,3,1) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>rating = [2,1,3]
<strong>输出：</strong>0
<strong>解释：</strong>根据题目条件，我们无法组建作战单位。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>rating = [1,2,3,4]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rating.length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>1 &lt;= rating[i] &lt;= 10^5</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numTeams(vector<int>& rating) 
    {
        if (rating.size() < 3) return 0;
        int ans = 0;
        for (int i = 0; i < rating.size(); i++)
        {
            for (int j = i + 1; j < rating.size(); j++)
            {
                for (int k = j + 1; k < rating.size(); k++)
                {
                    if ((rating[i] < rating[j] && rating[j] < rating[k])
                        || (rating[i] > rating[j] && rating[j] > rating[k]))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
```




