# `（简单）` [1518.water-bottles 换酒问题](https://leetcode-cn.com/problems/water-bottles/)

[contest](https://leetcode-cn.com/contest/weekly-contest-198/problems/water-bottles/)

### 题目描述
<p>小区便利店正在促销，用 <code>numExchange</code> 个空酒瓶可以兑换一瓶新酒。你购入了 <code>numBottles</code> 瓶酒。</p>

<p>如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。</p>

<p>请你计算 <strong>最多</strong> 能喝到多少瓶酒。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img style="height: 240px; width: 480px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/sample_1_1875.png" alt=""></strong></p>

<pre><strong>输入：</strong>numBottles = 9, numExchange = 3
<strong>输出：</strong>13
<strong>解释：</strong>你可以用 <code>3</code> 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 9 + 3 + 1 = 13 瓶酒。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="height: 240px; width: 790px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/19/sample_2_1875.png" alt=""></p>

<pre><strong>输入：</strong>numBottles = 15, numExchange = 4
<strong>输出：</strong>19
<strong>解释：</strong>你可以用 <code>4</code> 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 15 + 3 + 1 = 19 瓶酒。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>numBottles = 5, numExchange = 5
<strong>输出：</strong>6
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>numBottles = 2, numExchange = 3
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <=&nbsp;numBottles <= 100</code></li>
	<li><code>2 <=&nbsp;numExchange <= 100</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int drink = numBottles / numExchange;
            numBottles %= numExchange;
            numBottles += drink;
            ans += drink;
        }
        return ans;
    }
```




