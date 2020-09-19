# `（困难）` [LCP 24.5TxKeK 数字游戏](https://leetcode-cn.com/problems/5TxKeK/)

### 题目描述
<p>小扣在秋日市集入口处发现了一个数字游戏。主办方共有 <code>N</code> 个计数器，计数器编号为 <code>0 ~ N-1</code>。每个计数器上分别显示了一个数字，小扣按计数器编号升序将所显示的数字记于数组 <code>nums</code>。每个计数器上有两个按钮，分别可以实现将显示数字加一或减一。小扣每一次操作可以选择一个计数器，按下加一或减一按钮。</p>
<p>主办方请小扣回答出一个长度为 <code>N</code> 的数组，第 <code>i</code> 个元素(0 &lt;= i &lt; N)表示将 <code>0~i</code> 号计数器 <strong>初始</strong> 所示数字操作成满足所有条件 <code>nums[a]+1 == nums[a+1],(0 &lt;= a &lt; i)</code> 的最小操作数。回答正确方可进入秋日市集。</p>
<p>由于答案可能很大，请将每个最小操作数对 <code>1,000,000,007</code> 取余。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>nums = [3,4,5,1,6,7]</code></p>
<p>输出：<code>[0,0,0,5,6,7]</code></p>
<p>解释：<br>
i = 0，[3] 无需操作<br>
i = 1，[3,4] 无需操作；<br>
i = 2，[3,4,5] 无需操作；<br>
i = 3，将 [3,4,5,1] 操作成 [3,4,5,6], 最少 5 次操作；<br>
i = 4，将 [3,4,5,1,6] 操作成 [3,4,5,6,7], 最少 6 次操作；<br>
i = 5，将 [3,4,5,1,6,7] 操作成 [3,4,5,6,7,8]，最少 7 次操作；<br>
返回 [0,0,0,5,6,7]。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>nums = [1,2,3,4,5]</code></p>
<p>输出：<code>[0,0,0,0,0]</code></p>
<p>解释：对于任意计数器编号 i 都无需操作。</p>
</blockquote>
<p><strong>示例 3：</strong></p>
<blockquote>
<p>输入：<code>nums = [1,1,1,2,3,4]</code></p>
<p>输出：<code>[0,1,2,3,3,3]</code></p>
<p>解释：<br>
i = 0，无需操作；<br>
i = 1，将 [1,1] 操作成 [1,2] 或 [0,1] 最少 1 次操作；<br>
i = 2，将 [1,1,1] 操作成 [1,2,3] 或 [0,1,2]，最少 2 次操作；<br>
i = 3，将 [1,1,1,2] 操作成 [1,2,3,4] 或 [0,1,2,3]，最少 3 次操作；<br>
i = 4，将 [1,1,1,2,3] 操作成 [-1,0,1,2,3]，最少 3 次操作；<br>
i = 5，将 [1,1,1,2,3,4] 操作成 [-1,0,1,2,3,4]，最少 3 次操作；<br>
返回 [0,1,2,3,3,3]。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/er94lq/solution/er94lq-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<int> numsGame(vector<int>& nums) {

    }
};
```




