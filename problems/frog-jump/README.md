# `（困难）` [403.frog-jump 青蛙过河](https://leetcode-cn.com/problems/frog-jump/)

### 题目描述
<p>一只青蛙想要过河。 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。 青蛙可以跳上石子，但是不可以跳入水中。</p>

<p>给你石子的位置列表 <code>stones</code>（用单元格序号 <strong>升序</strong> 表示），&nbsp;请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。</p>

<p>开始时，&nbsp;青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃一个单位（即只能从单元格 1 跳至单元格 2 ）。</p>

<p>如果青蛙上一步跳跃了&nbsp;<code>k</code><em>&nbsp;</em>个单位，那么它接下来的跳跃距离只能选择为&nbsp;<code>k - 1</code>、<code>k</code><em>&nbsp;</em>或&nbsp;<code>k + 1</code> 个单位。&nbsp;另请注意，青蛙只能向前方（终点的方向）跳跃。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>stones = [0,1,3,5,6,8,12,17]
<strong>输出：</strong>true
<strong>解释：</strong>青蛙可以成功过河，按照如下方案跳跃：跳 1 个单位到第 2 块石子, 然后跳 2 个单位到第 3 块石子, 接着 跳 2 个单位到第 4 块石子, 然后跳 3 个单位到第 6 块石子, 跳 4 个单位到第 7 块石子, 最后，跳 5 个单位到第 8 个石子（即最后一块石子）。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>stones = [0,1,2,3,4,8,9,11]
<strong>输出：</strong>false
<strong>解释：</strong>这是因为第 5 和第 6 个石子之间的间距太大，没有可选的方案供青蛙跳跃过去。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= stones.length &lt;= 2000</code></li>
	<li><code>0 &lt;= stones[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>stones[0] == 0</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/frog-jump/solution/frog-jump-by-ikaruga-jw29/)

### 答题
``` C++
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<long long, int> dic;
        for (int i = 0; i < stones.size(); i++) {
            dic[stones[i]] = i;
        }

        vector<unordered_set<long long>> dp(stones.size());
        dp[0].insert(1);
        for (int i = 0; i + 1 < stones.size(); i++) {
            if (dp[i].empty()) continue;
            for (auto step : dp[i]) {
                long long target = stones[i] + step;
                if (dic.find(target) == dic.end()) continue;
                if (dic[target] + 1 == stones.size()) return true;
                for (long long x = max(1LL, step - 1); x < step + 2; x++) {
                    dp[dic[target]].insert(x);
                }
            }
        }
        return false;
    }
};
```




