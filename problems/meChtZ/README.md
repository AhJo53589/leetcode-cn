# `（困难）` [LCP 20.meChtZ 快速公交](https://leetcode-cn.com/problems/meChtZ/)

### 题目描述
<p>小扣打算去秋日市集，由于游客较多，小扣的移动速度受到了人流影响：</p>
<ul>
<li>小扣从 <code>x</code> 号站点移动至 <code>x + 1</code> 号站点需要花费的时间为 <code>inc</code>；</li>
<li>小扣从 <code>x</code> 号站点移动至 <code>x - 1</code> 号站点需要花费的时间为 <code>dec</code>。</li>
</ul>
<p>现有 <code>m</code> 辆公交车，编号为 <code>0</code> 到 <code>m-1</code>。小扣也可以通过搭乘编号为 <code>i</code> 的公交车，从 <code>x</code> 号站点移动至 <code>jump[i]*x</code> 号站点，耗时仅为 <code>cost[i]</code>。小扣可以搭乘任意编号的公交车且搭乘公交次数不限。</p>
<p>假定小扣起始站点记作 <code>0</code>，秋日市集站点记作 <code>target</code>，请返回小扣抵达秋日市集最少需要花费多少时间。由于数字较大，最终答案需要对 1000000007 (1e9 + 7) 取模。</p>
<p>注意：小扣可在移动过程中到达编号大于 <code>target</code> 的站点。</p>
<p><strong>示例 1：</strong></p>
<blockquote>
<p>输入：<code>target = 31, inc =  5, dec = 3, jump = [6], cost = [10]</code></p>
<p>输出：<code>33</code></p>
<p>解释：<br>
小扣步行至 1 号站点，花费时间为 5；<br>
小扣从 1 号站台搭乘 0 号公交至 6 * 1 = 6 站台，花费时间为 10；<br>
小扣从 6 号站台步行至 5 号站台，花费时间为 3；<br>
小扣从 5 号站台搭乘 0 号公交至 6 * 5 = 30 站台，花费时间为 10；<br>
小扣从 30 号站台步行至 31 号站台，花费时间为 5；<br>
最终小扣花费总时间为 33。</p>
</blockquote>
<p><strong>示例 2：</strong></p>
<blockquote>
<p>输入：<code>target = 612, inc =  4, dec = 5, jump = [3,6,8,11,5,10,4], cost = [4,7,6,3,7,6,4]</code></p>
<p>输出：<code>26</code></p>
<p>解释：<br>
小扣步行至 1 号站点，花费时间为 4；<br>
小扣从 1 号站台搭乘 0 号公交至 3 * 1 = 3 站台，花费时间为 4；<br>
小扣从 3 号站台搭乘 3 号公交至 11 * 3 = 33 站台，花费时间为 3；<br>
小扣从 33 号站台步行至 34 站台，花费时间为 4；<br>
小扣从 34 号站台搭乘 0 号公交至 3 * 34 = 102 站台，花费时间为 4；<br>
小扣从 102 号站台搭乘 1 号公交至 6 * 102 = 612 站台，花费时间为 7；<br>
最终小扣花费总时间为 26。</p>
</blockquote>
<p><strong>提示：</strong></p>
<ul>
<li><code>1 &lt;= target &lt;= 10^9</code></li>
<li><code>1 &lt;= jump.length, cost.length &lt;= 10</code></li>
<li><code>2 &lt;= jump[i] &lt;= 10^6</code></li>
<li><code>1 &lt;= inc, dec, cost[i] &lt;= 10^6</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {

    }
};
```




