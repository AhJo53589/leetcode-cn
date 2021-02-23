# `（中等）` [1052.grumpy-bookstore-owner 爱生气的书店老板](https://leetcode-cn.com/problems/grumpy-bookstore-owner/)

### 题目描述
<p>今天，书店老板有一家店打算试营业&nbsp;<code>customers.length</code>&nbsp;分钟。每分钟都有一些顾客（<code>customers[i]</code>）会进入书店，所有这些顾客都会在那一分钟结束后离开。</p>

<p>在某些时候，书店老板会生气。 如果书店老板在第 <code>i</code> 分钟生气，那么 <code>grumpy[i] = 1</code>，否则 <code>grumpy[i] = 0</code>。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。</p>

<p>书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续&nbsp;<code>X</code> 分钟不生气，但却只能使用一次。</p>

<p>请你返回这一天营业下来，最多有多少客户能够感到满意的数量。<br>
&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
<strong>输出：</strong>16
<strong>解释：
</strong>书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= X &lt;=&nbsp;customers.length ==&nbsp;grumpy.length &lt;= 20000</code></li>
	<li><code>0 &lt;=&nbsp;customers[i] &lt;= 1000</code></li>
	<li><code>0 &lt;=&nbsp;grumpy[i] &lt;= 1</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/grumpy-bookstore-owner/solution/grumpy-bookstore-owner-by-ikaruga-15bg/)

### 答题
``` C++
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans = 0;
        int window = 0;
        for (int i = 0, j = 0; j < customers.size(); j++) {
            if (j - i == X) {
                window -= (grumpy[i] == 1) ? customers[i] : 0;
                i++;
            }
            window += (grumpy[j] == 1) ? customers[j] : 0;
            ans = max(ans, window);
        }

        for (int i = 0; i < customers.size(); i++) {
            ans += (grumpy[i] == 0) ? customers[i] : 0;
        }

        return ans;
    }
};
```




