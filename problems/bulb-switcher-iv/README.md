# `（中等）` [5473.bulb-switcher-iv 灯泡开关 IV](https://leetcode-cn.com/problems/bulb-switcher-iv/)

[contest](https://leetcode-cn.com/contest/weekly-contest-199/problems/bulb-switcher-iv/)

### 题目描述
<p>房间中有 <code>n</code> 个灯泡，编号从 <code>0</code> 到 <code>n-1</code> ，自左向右排成一行。最开始的时候，所有的灯泡都是 <strong>关</strong> 着的。</p>

<p>请你设法使得灯泡的开关状态和 <code>target</code> 描述的状态一致，其中 <code>target[i]</code> 等于 <code>1</code> 第 <code>i</code> 个灯泡是开着的，等于 <code>0</code> 意味着第 <code>i</code> 个灯是关着的。</p>

<p>有一个开关可以用于翻转灯泡的状态，翻转操作定义如下：</p>

<ul>
	<li>选择当前配置下的任意一个灯泡（下标为 <code>i</code> ）</li>
	<li>翻转下标从 <code>i</code> 到 <code>n-1</code> 的每个灯泡</li>
</ul>

<p>翻转时，如果灯泡的状态为 <code>0</code> 就变为 <code>1</code>，为 <code>1</code> 就变为 <code>0</code> 。</p>

<p>返回达成 <code>target</code> 描述的状态所需的 <strong>最少</strong> 翻转次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = "10111"
<strong>输出：</strong>3
<strong>解释：</strong>初始配置 "00000".
从第 3 个灯泡（下标为 2）开始翻转 "00000" -&gt; "00111"
从第 1 个灯泡（下标为 0）开始翻转 "00111" -&gt; "11000"
从第 2 个灯泡（下标为 1）开始翻转 "11000" -&gt; "10111"
至少需要翻转 3 次才能达成 target 描述的状态</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = "101"
<strong>输出：</strong>3
<strong>解释：</strong>"000" -&gt; "111" -&gt; "100" -&gt; "101".
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>target = "00000"
<strong>输出：</strong>0
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>target = "001011101"
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 10^5</code></li>
	<li><code>target[i] == '0'</code> 或者 <code>target[i] == '1'</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
    int minFlips(string target) {
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == '0' + cur) continue;
            cur = (cur + 1) % 2;
            ans++;
        }
        return ans;
    }
```




