# `（困难）` [1467.probability-of-a-two-boxes-having-the-same-number-of-distinct-balls 两个盒子中球的颜色数相同的概率](https://leetcode-cn.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/)

[contest](https://leetcode-cn.com/contest/weekly-contest-191/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/)

### 题目描述
<p>桌面上有 <code>2n</code> 个颜色不完全相同的球，球上的颜色共有 <code>k</code> 种。给你一个大小为 <code>k</code> 的整数数组 <code>balls</code> ，其中 <code>balls[i]</code> 是颜色为&nbsp;<code>i</code> 的球的数量。</p>

<p>所有的球都已经 <strong>随机打乱顺序</strong> ，前 <code>n</code> 个球放入第一个盒子，后 <code>n</code> 个球放入另一个盒子（请认真阅读示例 2 的解释部分）。</p>

<p><strong>注意：</strong>这两个盒子是不同的。例如，两个球颜色分别为 <code>a</code> 和 <code>b</code>，盒子分别为 <code>[]</code> 和 <code>()</code>，那么 <code>[a] (b)</code> 和 <code>[b] (a)</code> 这两种分配方式是不同的（请认真阅读示例 1 的解释部分）。</p>

<p>请计算「两个盒子中球的颜色数相同」的情况的概率。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>balls = [1,1]
<strong>输出：</strong>1.00000
<strong>解释：</strong>球平均分配的方式只有两种：
- 颜色为 1 的球放入第一个盒子，颜色为 2 的球放入第二个盒子
- 颜色为 2 的球放入第一个盒子，颜色为 1 的球放入第二个盒子
这两种分配，两个盒子中球的颜色数都相同。所以概率为 2/2 = 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>balls = [2,1,1]
<strong>输出：</strong>0.66667
<strong>解释：</strong>球的列表为 [1, 1, 2, 3]
随机打乱，得到 12 种等概率的不同打乱方案，每种方案概率为 1/12 ：
[1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], [3,1 / 2,1], [3,2 / 1,1]
然后，我们将前两个球放入第一个盒子，后两个球放入第二个盒子。
这 12 种可能的随机打乱方式中的 8 种满足「两个盒子中球的颜色数相同」。
概率 = 8/12 = 0.66667
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>balls = [1,2,1,2]
<strong>输出：</strong>0.60000
<strong>解释：</strong>球的列表为 [1, 2, 2, 3, 4, 4]。要想显示所有 180 种随机打乱方案是很难的，但只检查「两个盒子中球的颜色数相同」的 108 种情况是比较容易的。
概率 = 108 / 180 = 0.6 。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>balls = [3,2,1]
<strong>输出：</strong>0.30000
<strong>解释：</strong>球的列表为 [1, 1, 1, 2, 2, 3]。要想显示所有 60 种随机打乱方案是很难的，但只检查「两个盒子中球的颜色数相同」的 18 种情况是比较容易的。
概率 = 18 / 60 = 0.3 。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>balls = [6,6,6,6,6,6]
<strong>输出：</strong>0.90327
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= balls.length <= 8</code></li>
	<li><code>1 <= balls[i] <= 6</code></li>
	<li><code>sum(balls)</code> 是偶数</li>
	<li>答案与真实值误差在 <code>10^-5</code> 以内，则被视为正确答案</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    double getProbability(vector<int>& balls) {

    }
};
```




