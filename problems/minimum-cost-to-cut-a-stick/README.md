# `（困难）` [1547.minimum-cost-to-cut-a-stick 切棍子的最小成本](https://leetcode-cn.com/problems/minimum-cost-to-cut-a-stick/)

[contest](https://leetcode-cn.com/contest/weekly-contest-201/problems/minimum-cost-to-cut-a-stick/)

### 题目描述
<p>有一根长度为 <code>n</code> 个单位的木棍，棍上从 <code>0</code> 到 <code>n</code> 标记了若干位置。例如，长度为 <strong>6</strong> 的棍子可以标记如下：</p>

<p><img style="height: 111px; width: 521px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/09/statement.jpg" alt=""></p>

<p>给你一个整数数组 <code>cuts</code> ，其中 <code>cuts[i]</code> 表示你需要将棍子切开的位置。</p>

<p>你可以按顺序完成切割，也可以根据需要更改切割的顺序。</p>

<p>每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。</p>

<p>返回切棍子的 <strong>最小总成本</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="height: 284px; width: 350px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/09/e1.jpg" alt=""></p>

<pre><strong>输入：</strong>n = 7, cuts = [1,3,4,5]
<strong>输出：</strong>16
<strong>解释：</strong>按 [1, 3, 4, 5] 的顺序切割的情况如下所示：
<img style="height: 284px; width: 350px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/09/e11.jpg" alt="">
第一次切割长度为 7 的棍子，成本为 7 。第二次切割长度为 6 的棍子（即第一次切割得到的第二根棍子），第三次切割为长度 4 的棍子，最后切割长度为 3 的棍子。总成本为 7 + 6 + 4 + 3 = 20 。
而将切割顺序重新排列为 [3, 5, 1, 4] 后，总成本 = 16（如示例图中 7 + 4 + 3 + 2 = 16）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 9, cuts = [5,6,1,4,2]
<strong>输出：</strong>22
<strong>解释：</strong>如果按给定的顺序切割，则总成本为 25 。总成本 <= 25 的切割顺序很多，例如，[4，6，5，2，1] 的总成本 = 22，是所有可能方案中成本最小的。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 10^6</code></li>
	<li><code>1 <= cuts.length <= min(n - 1, 100)</code></li>
	<li><code>1 <= cuts[i] <= n - 1</code></li>
	<li><code>cuts</code> 数组中的所有整数都 <strong>互不相同</strong></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> sticks;
        sticks.reserve(cuts.size() + 1);
        int prevCut = 0;
        for (auto cut : cuts) {
            sticks.push_back(cut - prevCut);
            prevCut = cut;
        }
        sticks.push_back(n - prevCut);
        int m = sticks.size();
        // dp[i][j]表示sticks[i..j]合并需要的最小代价
        vector<vector<int>> dp(m, vector<int>(m, numeric_limits<int>::max()));
        vector<int> prefixSum(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            dp[i][i] = 0;
            prefixSum[i + 1] = prefixSum[i] + sticks[i];
        }
        for (int count = 1; count <= m; ++count) {
            for (int i = 0; i + count < m; ++i) {
                int j = i + count;
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] += prefixSum[j + 1] - prefixSum[i];
            }
        }
        return dp[0][m - 1];
    }
};
```




