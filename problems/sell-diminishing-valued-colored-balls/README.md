# `（中等）` [5563.sell-diminishing-valued-colored-balls 销售价值减少的颜色球](https://leetcode-cn.com/problems/sell-diminishing-valued-colored-balls/)

[contest](https://leetcode-cn.com/contest/weekly-contest-214/problems/sell-diminishing-valued-colored-balls/)

### 题目描述
<p>你有一些球的库存&nbsp;<code>inventory</code>&nbsp;，里面包含着不同颜色的球。一个顾客想要&nbsp;<strong>任意颜色</strong> 总数为&nbsp;<code>orders</code>&nbsp;的球。</p>

<p>这位顾客有一种特殊的方式衡量球的价值：每个球的价值是目前剩下的&nbsp;<strong>同色球</strong>&nbsp;的数目。比方说还剩下&nbsp;<code>6</code>&nbsp;个黄球，那么顾客买第一个黄球的时候该黄球的价值为&nbsp;<code>6</code>&nbsp;。这笔交易以后，只剩下&nbsp;<code>5</code>&nbsp;个黄球了，所以下一个黄球的价值为&nbsp;<code>5</code>&nbsp;（也就是球的价值随着顾客购买同色球是递减的）</p>

<p>给你整数数组&nbsp;<code>inventory</code>&nbsp;，其中&nbsp;<code>inventory[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;种颜色球一开始的数目。同时给你整数&nbsp;<code>orders</code>&nbsp;，表示顾客总共想买的球数目。你可以按照 <strong>任意顺序</strong>&nbsp;卖球。</p>

<p>请你返回卖了 <code>orders</code>&nbsp;个球以后 <strong>最大</strong>&nbsp;总价值之和。由于答案可能会很大，请你返回答案对 <code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;<strong>取余数</strong>&nbsp;的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img style="width: 480px; height: 270px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/08/jj.gif" alt="">
<pre><b>输入：</b>inventory = [2,5], orders = 4
<b>输出：</b>14
<b>解释：</b>卖 1 个第一种颜色的球（价值为 2 )，卖 3 个第二种颜色的球（价值为 5 + 4 + 3）。
最大总和为 2 + 5 + 4 + 3 = 14 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>inventory = [3,5], orders = 6
<b>输出：</b>19
<strong>解释：</strong>卖 2 个第一种颜色的球（价值为 3 + 2），卖 4 个第二种颜色的球（价值为 5 + 4 + 3 + 2）。
最大总和为 3 + 2 + 5 + 4 + 3 + 2 = 19 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>inventory = [2,8,4,10,6], orders = 20
<b>输出：</b>110
</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>inventory = [1000000000], orders = 1000000000
<b>输出：</b>21
<strong>解释：</strong>卖 1000000000 次第一种颜色的球，总价值为 500000000500000000 。 500000000500000000 对 10<sup>9 </sup>+ 7 取余为 21 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= inventory.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= inventory[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= orders &lt;= min(sum(inventory[i]), 10<sup>9</sup>)</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sell-diminishing-valued-colored-balls/solution/sell-diminishing-valued-colored-balls-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int mod = 1e9 + 7;

        sort(inventory.rbegin(), inventory.rend());
        int low = 0;
        int high = INT_MAX;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(inventory, orders, mid)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        long long ans = 0;
        for (int i = 0; i < inventory.size() && orders != 0; i++) {
            long long cnt = min(inventory[i] - low, orders);
            if (cnt < 0) break;
            orders -= cnt;

            long long a = inventory[i];
            long long b = inventory[i] - cnt + 1;
            long long sum = (a + b) * cnt / 2;
            ans += sum;
            ans %= mod;
        }
        ans += (long long)orders * (long long)low;
        ans %= mod;
        return ans;
    }

    bool check(vector<int>& inventory, int orders, int target) {
        long long cnt = 0;
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i] < target) break;
            cnt += inventory[i] - target;
        }
        return cnt >= orders;
    }
};
```




