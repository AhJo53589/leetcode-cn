# `（简单）` [905.sort-array-by-parity 按奇偶排序数组](https://leetcode-cn.com/problems/sort-array-by-parity/)

### 题目描述
<p>给定一个非负整数数组 <code>A</code>，返回一个数组，在该数组中，&nbsp;<code>A</code> 的所有偶数元素之后跟着所有奇数元素。</p>

<p>你可以返回满足此条件的任何数组作为答案。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[3,1,2,4]
<strong>输出：</strong>[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= A.length <= 5000</code></li>
	<li><code>0 <= A[i] <= 5000</code></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sort-array-by-parity/solution/sort-array-by-parity-by-ikaruga/)

### 答题
``` C++
    vector<int> sortArrayByParity(vector<int>& A)
    {
        int l = 0;
        int r = A.size() - 1;
        while (l < r)
        {
            while (l < r && A[l] % 2 == 0)
            {
                l++;
            }
            swap(A[l], A[r--]);
        }
        return A;
    }
```




