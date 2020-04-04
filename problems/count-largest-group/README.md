# `（简单）` [5360.count-largest-group 统计最大组的数目](https://leetcode-cn.com/problems/count-largest-group/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-23/problems/count-largest-group/)

### 题目描述
<p>给你一个整数 <code>n</code>&nbsp;。请你先将从 <code>1</code>&nbsp;到 <code>n</code> 的所有整数按 10 进制对各个数位求和，然后把数位和相等的数字放到同一个组中。</p>

<p>请你统计每个组的数字数目，并返回数字数目并列最多的组有多少个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 13
<strong>输出：</strong>4
<strong>解释：</strong>总共有 9 个组，将 1 到 13 按数位求和后这些组分别是：
[1,10]，[2,11]，[3,12]，[4,13]，[5]，[6]，[7]，[8]，[9]。总共有 4 个组拥有的数字并列最多。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>总共有 2 个大小为 1 的组 [1]，[2]。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 15
<strong>输出：</strong>6
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 24
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
    int f(int x)
    {
        int cnt = 0;
        while (x != 0)
        {
            cnt += (x % 10);
            x /= 10;
        }
        return cnt;
    }

    int countLargestGroup(int n) 
    {
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            mp[f(i)]++;
        }

        int ans = 0;
        int cnt = 0;
        for (auto it : mp)
        {
            if (cnt < it.second)
            {
                cnt = it.second;
                ans = 0;
            }
            ans += (cnt == it.second);
        }
        return ans;
    }
```




