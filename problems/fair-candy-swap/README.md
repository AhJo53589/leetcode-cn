# `（简单）` [888.fair-candy-swap 公平的糖果交换](https://leetcode-cn.com/problems/fair-candy-swap/)

### 题目描述
<p>爱丽丝和鲍勃有不同大小的糖果棒：<code>A[i]</code> 是爱丽丝拥有的第 <code>i</code>&nbsp;块糖的大小，<code>B[j]</code> 是鲍勃拥有的第 <code>j</code>&nbsp;块糖的大小。</p>

<p>因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。<em>（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）</em></p>

<p>返回一个整数数组 <code>ans</code>，其中 <code>ans[0]</code> 是爱丽丝必须交换的糖果棒的大小，<code>ans[1]</code>&nbsp;是 Bob 必须交换的糖果棒的大小。</p>

<p>如果有多个答案，你可以返回其中任何一个。保证答案存在。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>A = [1,1], B = [2,2]
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>A = [1,2], B = [2,3]
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>A = [2], B = [1,3]
<strong>输出：</strong>[2,3]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>A = [1,2,5], B = [2,4]
<strong>输出：</strong>[5,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= A.length <= 10000</code></li>
	<li><code>1 <= B.length <= 10000</code></li>
	<li><code>1 <= A[i] <= 100000</code></li>
	<li><code>1 <= B[i] <= 100000</code></li>
	<li>保证爱丽丝与鲍勃的糖果总量不同。</li>
	<li>答案肯定存在。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/fair-candy-swap/solution/fair-candy-swap-by-ikaruga/)

### 答题
``` C++
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
    {
        long long sumA = accumulate(A.begin(), A.end(), 0);
        long long sumB = accumulate(B.begin(), B.end(), 0);
        int diff = (sumA - sumB) / 2;
        
        unordered_map<int, int> mp;
        for (int i = 0; i < A.size(); i++)
        {
            mp[A[i] - diff] = i;
        }
        for (int j = 0; j < B.size(); j++)
        {
            if (mp.count(B[j]) == 0) continue;
            return { A[mp[B[j]]], B[j] };
        }
        return {};
    }
```




