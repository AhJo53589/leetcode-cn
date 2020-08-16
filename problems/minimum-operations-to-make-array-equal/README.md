# `（中等）` [5488.minimum-operations-to-make-array-equal 使数组中所有元素相等的最小操作数](https://leetcode-cn.com/problems/minimum-operations-to-make-array-equal/)

[contest](https://leetcode-cn.com/contest/weekly-contest-202/problems/minimum-operations-to-make-array-equal/)

### 题目描述
<p>存在一个长度为 <code>n</code> 的数组 <code>arr</code> ，其中 <code>arr[i] = (2 * i) + 1</code> （ <code>0 <= i < n</code> ）。</p>

<p>一次操作中，你可以选出两个下标，记作 <code>x</code> 和 <code>y</code> （ <code>0 <= x, y < n</code> ）并使 <code>arr[x]</code> 减去 <code>1</code> 、<code>arr[y]</code> 加上 <code>1</code> （即 <code>arr[x] -=1 </code>且 <code>arr[y] += 1</code> ）。最终的目标是使数组中的所有元素都 <strong>相等</strong> 。题目测试用例将会 <strong>保证</strong> ：在执行若干步操作后，数组中的所有元素最终可以全部相等。</p>

<p>给你一个整数 <code>n</code>，即数组的长度。请你返回使数组 <code>arr</code> 中所有元素相等所需的 <strong>最小操作数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>2
<strong>解释：</strong>arr = [1, 3, 5]
第一次操作选出 x = 2 和 y = 0，使数组变为 [2, 3, 4]
第二次操作继续选出 x = 2 和 y = 0，数组将会变成 [3, 3, 3]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 6
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10^4</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
    int minOperations(int n) {
        if (n % 2 == 0) {
            return n * n / 4;
        }
        else {
            return (2 + 2 * (n / 2)) * (n / 2) / 2;
        }
    }
```




