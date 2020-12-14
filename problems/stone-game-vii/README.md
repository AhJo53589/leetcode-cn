# `（中等）` [5627.stone-game-vii 石子游戏 VII](https://leetcode-cn.com/problems/stone-game-vii/)

[contest](https://leetcode-cn.com/contest/weekly-contest-219/problems/stone-game-vii/)

### 题目描述
<div class="notranslate"><p>石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，<strong>爱丽丝先开始</strong> 。</p>

<p>有 <code>n</code> 块石子排成一排。每个玩家的回合中，可以从行中 <strong>移除</strong> 最左边的石头或最右边的石头，并获得与该行中剩余石头值之 <strong>和</strong> 相等的得分。当没有石头可移除时，得分较高者获胜。</p>

<p>鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力 <strong>减小得分的差值</strong> 。爱丽丝的目标是最大限度地 <strong>扩大得分的差值</strong> 。</p>

<p>给你一个整数数组&nbsp;<code>stones</code> ，其中 <code>stones[i]</code> 表示 <strong>从左边开始</strong> 的第 <code>i</code> 个石头的值，如果爱丽丝和鲍勃都 <strong>发挥出最佳水平</strong> ，请返回他们 <strong>得分的差值</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>stones = [5,3,1,4,2]
<strong>输出：</strong>6
<strong>解释：</strong>
- 爱丽丝移除 2 ，得分 5 + 3 + 1 + 4 = 13 。游戏情况：爱丽丝 = 13 ，鲍勃 = 0 ，石子 = [5,3,1,4] 。
- 鲍勃移除 5 ，得分 3 + 1 + 4 = 8 。游戏情况：爱丽丝 = 13 ，鲍勃 = 8 ，石子 = [3,1,4] 。
- 爱丽丝移除 3 ，得分 1 + 4 = 5 。游戏情况：爱丽丝 = 18 ，鲍勃 = 8 ，石子 = [1,4] 。
- 鲍勃移除 1 ，得分 4 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [4] 。
- 爱丽丝移除 4 ，得分 0 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [] 。
得分的差值 18 - 12 = 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>stones = [7,90,5,1,100,10,10,2]
<strong>输出：</strong>122</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= stones[i] &lt;= 1000</code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vv = vector<vector<int>>(stones.size(), vector<int>(stones.size(), -1));
        int sum = accumulate(stones.begin(), stones.end(), 0);
		return dfs(stones, 0, stones.size() - 1, sum, 0);
    }

    int dfs(vector<int>& stones, int left, int right, int sum, int idx) {
        if (vv[left][right] != -1) {
            return vv[left][right];
        }

        if (left == right) return 0;
        int sc_l = dfs(stones, left + 1, right, sum - stones[left], (idx + 1) % 2);
        int sc_r = dfs(stones, left, right - 1, sum - stones[right], (idx + 1) % 2);

        int ret;
        if (idx == 0) {
            ret = max(sum - stones[left] + sc_l, sum - stones[right] + sc_r);
        }
        else {
            ret = min(sc_l - (sum - stones[left]), sc_r - (sum - stones[right]));
        }
        vv[left][right] = ret;
        return ret;
	}

private:
    vector<vector<int>> vv;
};
```




