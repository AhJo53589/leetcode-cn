# `（困难）` [5498.stone-game-v 石子游戏 V](https://leetcode-cn.com/problems/stone-game-v/)

[contest](https://leetcode-cn.com/contest/weekly-contest-203/problems/stone-game-v/)

### 题目描述
<p>几块石子 <strong>排成一行</strong> ，每块石子都有一个关联值，关联值为整数，由数组 <code>stoneValue</code> 给出。</p>
<p>游戏中的每一轮：Alice 会将这行石子分成两个 <strong>非空行</strong>（即，左侧行和右侧行）；Bob 负责计算每一行的值，即此行中所有石子的值的总和。Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始。</p>
<p>只 <strong>剩下一块石子</strong> 时，游戏结束。Alice 的分数最初为 <strong><code>0</code></strong> 。</p>
<p>返回 <strong>Alice 能够获得的最大分数</strong><em> 。</em></p>
<p>&nbsp;</p>
<p><strong>示例 1：</strong></p>
<pre><strong>输入：</strong>stoneValue = [6,2,3,4,5,5]
<strong>输出：</strong>18
<strong>解释：</strong>在第一轮中，Alice 将行划分为 [6，2，3]，[4，5，5] 。左行的值是 11 ，右行的值是 14 。Bob 丢弃了右行，Alice 的分数现在是 11 。
在第二轮中，Alice 将行分成 [6]，[2，3] 。这一次 Bob 扔掉了左行，Alice 的分数变成了 16（11 + 5）。
最后一轮 Alice 只能将行分成 [2]，[3] 。Bob 扔掉右行，Alice 的分数现在是 18（16 + 2）。游戏结束，因为这行只剩下一块石头了。
</pre>

<p><strong>示例 2：</strong></p>
<pre><strong>输入：</strong>stoneValue = [7,7,7,7,7,7,7]
<strong>输出：</strong>28
</pre>

<p><strong>示例 3：</strong></p>
<pre><strong>输入：</strong>stoneValue = [4]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>
<p><strong>提示：</strong></p>
<ul>
	<li><code>1 <= stoneValue.length <= 500</code></li>
	<li><code>1 <=&nbsp;stoneValue[i] <= 10^6</code></li>
</ul>

---
### 思路
```

```



### 答题
``` C++
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int sum = 0;
        for (int i = 0; i < stoneValue.size(); i++) {
            swap(sum, stoneValue[i]);
            sum += stoneValue[i];
        }
        stoneValue.push_back(sum);

        dp = vector<vector<int>>(stoneValue.size(), vector<int>(stoneValue.size(), -1));
        return dfs(stoneValue, 1, stoneValue.size() - 1);
    }

    int dfs(vector<int>& stoneValue, int left, int right) {
        if (dp[left][right] != -1) return dp[left][right];

        if (left == right) return 0;

        int maxVal = 0;

        if (left + 1 == right) {
            int l = stoneValue[left] - stoneValue[left - 1];
            int r = stoneValue[right] - stoneValue[left];
            maxVal = (l < r) ? l : r;
            dp[left][right] = maxVal;
            return maxVal;
        }

        for (int i = left; i < right; i++) {
            int l = stoneValue[i] - stoneValue[left - 1];
            int r = stoneValue[right] - stoneValue[i];
            if (l <= r) {
                maxVal = max(maxVal, l + dfs(stoneValue, left, i));
            }
            if (l >= r) {
                maxVal = max(maxVal, r + dfs(stoneValue, i + 1, right));
            }
        }
        dp[left][right] = maxVal;
        return maxVal;
    }

private:
    vector<vector<int>> dp;
};
```




