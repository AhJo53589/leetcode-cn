# `（简单）` [852.peak-index-in-a-mountain-array 山脉数组的峰顶索引](https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/)

### 题目描述
<p>我们把符合下列属性的数组&nbsp;<code>A</code>&nbsp;称作山脉：</p>

<ul>
	<li><code>A.length >= 3</code></li>
	<li>存在 <code>0 < i&nbsp;< A.length - 1</code> 使得<code>A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]</code></li>
</ul>

<p>给定一个确定为山脉的数组，返回任何满足&nbsp;<code>A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]</code>&nbsp;的 <code>i</code>&nbsp;的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[0,1,0]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[0,2,1,0]
<strong>输出：</strong>1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>3 <= A.length <= 10000</code></li>
	<li>0 <= A[i] <= 10^6</li>
	<li>A 是如上定义的山脉</li>
</ol>

<p>&nbsp;</p>


---
### 思路
```
```



### 答题
``` C++
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0;
        int r = A.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[m - 1] < A[m] && A[m] > A[m + 1]) return m;
            if (A[m - 1] < A[m]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return l;
    }
```




