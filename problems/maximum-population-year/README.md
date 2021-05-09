# `（简单）` [5750.maximum-population-year 人口最多的年份](https://leetcode-cn.com/problems/maximum-population-year/)

[contest](https://leetcode-cn.com/contest/weekly-contest-240/problems/maximum-population-year/)

### 题目描述
<div class="notranslate"><p>给你一个二维整数数组 <code>logs</code> ，其中每个 <code>logs[i] = [birth<sub>i</sub>, death<sub>i</sub>]</code> 表示第 <code>i</code> 个人的出生和死亡年份。</p>

<p>年份 <code>x</code> 的 <strong>人口</strong> 定义为这一年期间活着的人的数目。第 <code>i</code> 个人被计入年份 <code>x</code> 的人口需要满足：<code>x</code> 在闭区间 <code>[birth<sub>i</sub>, death<sub>i</sub> - 1]</code> 内。注意，人不应当计入他们死亡当年的人口中。</p>

<p>返回 <strong>人口最多</strong> 且 <strong>最早</strong> 的年份。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>logs = [[1993,1999],[2000,2010]]
<strong>输出：</strong>1993
<strong>解释：</strong>人口最多为 1 ，而 1993 是人口为 1 的最早年份。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>logs = [[1950,1961],[1960,1971],[1970,1981]]
<strong>输出：</strong>1960
<strong>解释：</strong> 
人口最多为 2 ，分别出现在 1960 和 1970 。
其中最早年份是 1960 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= logs.length &lt;= 100</code></li>
	<li><code>1950 &lt;= birth<sub>i</sub> &lt; death<sub>i</sub> &lt;= 2050</code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-population-year/solution/maximum-population-year-by-ikaruga-g90l/)

### 答题
``` C++
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> birth(logs.size());
        vector<int> death(logs.size());
        for (int i = 0; i < logs.size(); i++) {
            birth[i] = logs[i][0];
            death[i] = logs[i][1];
        }
        sort(birth.begin(), birth.end());
        sort(death.begin(), death.end());

        int maxP = 0;
        int ans = 0;
        int p = 0;
        for (int i = 0, j = 0; i < birth.size(); i++) {
            p++;
            while (death[j] <= birth[i]) {
                p--;
                j++;
            }

            if (p > maxP) {
                maxP = p;
                ans = birth[i];
            }
        }
        return ans;
    }
};
```




