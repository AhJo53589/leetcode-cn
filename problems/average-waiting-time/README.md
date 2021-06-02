# `（中等）` [1701.average-waiting-time 平均等待时间](https://leetcode-cn.com/problems/average-waiting-time/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-42/problems/average-waiting-time/)

### 题目描述
<div class="notranslate"><p>有一个餐厅，只有一位厨师。你有一个顾客数组&nbsp;<code>customers</code>&nbsp;，其中&nbsp;<code>customers[i] = [arrival<sub>i</sub>, time<sub>i</sub>]</code>&nbsp;：</p>

<ul>
	<li><code>arrival<sub>i</sub></code>&nbsp;是第&nbsp;<code>i</code>&nbsp;位顾客到达的时间，到达时间按 <strong>非递减</strong> 顺序排列。</li>
	<li><code>time<sub>i</sub></code>&nbsp;是给第 <code>i</code>&nbsp;位顾客做菜需要的时间。</li>
</ul>

<p>当一位顾客到达时，他将他的订单给厨师，厨师一旦空闲的时候就开始做这位顾客的菜。每位顾客会一直等待到厨师完成他的订单。厨师同时只能做一个人的订单。厨师会严格按照 <strong>订单给他的顺序</strong>&nbsp;做菜。</p>

<p>请你返回所有顾客需要等待的 <strong>平均&nbsp;</strong>时间。与标准答案误差在&nbsp;<code>10<sup>-5</sup></code>&nbsp;范围以内，都视为正确结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>customers = [[1,2],[2,5],[4,3]]
<b>输出：</b>5.00000
<strong>解释：
</strong>1) 第一位顾客在时刻 1 到达，厨师拿到他的订单并在时刻 1 立马开始做菜，并在时刻 3 完成，第一位顾客等待时间为 3 - 1 = 2 。
2) 第二位顾客在时刻 2 到达，厨师在时刻 3 开始为他做菜，并在时刻 8 完成，第二位顾客等待时间为 8 - 2 = 6 。
3) 第三位顾客在时刻 4 到达，厨师在时刻 8 开始为他做菜，并在时刻 11 完成，第三位顾客等待时间为 11 - 4 = 7 。
平均等待时间为 (2 + 6 + 7) / 3 = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>customers = [[5,2],[5,4],[10,3],[20,1]]
<b>输出：</b>3.25000
<strong>解释：
</strong>1) 第一位顾客在时刻 5 到达，厨师拿到他的订单并在时刻 5 立马开始做菜，并在时刻 7 完成，第一位顾客等待时间为 7 - 5 = 2 。
2) 第二位顾客在时刻 5 到达，厨师在时刻 7 开始为他做菜，并在时刻 11 完成，第二位顾客等待时间为 11 - 5 = 6 。
3) 第三位顾客在时刻 10 到达，厨师在时刻 11 开始为他做菜，并在时刻 14 完成，第三位顾客等待时间为 14 - 10 = 4 。
4) 第四位顾客在时刻 20 到达，厨师拿到他的订单并在时刻 20 立马开始做菜，并在时刻 21 完成，第四位顾客等待时间为 21 - 20 = 1 。
平均等待时间为 (2 + 6 + 4 + 1) / 4 = 3.25 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= customers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arrival<sub>i</sub>, time<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>arrival<sub>i&nbsp;</sub>&lt;= arrival<sub>i+1</sub></code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/average-waiting-time/solution/average-waiting-time-by-ikaruga-3iej/)

### 答题
``` C++
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int cur = 0;
        for (auto& c : customers) {
            cur = max(cur, c[0]);
            cur += c[1];
            ans += cur - c[0];
        }
        return ans / (double)customers.size();
    }
};
```




