# `（中等）` [945.minimum-increment-to-make-array-unique 使数组唯一的最小增量](https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/)

### 题目描述
<p>给定整数数组 A，每次 <em>move</em> 操作将会选择任意&nbsp;<code>A[i]</code>，并将其递增&nbsp;<code>1</code>。</p>

<p>返回使 <code>A</code>&nbsp;中的每个值都是唯一的最少操作次数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入：</strong>[1,2,2]
<strong>输出：</strong>1
<strong>解释：</strong>经过一次 <em>move</em> 操作，数组将变为 [1, 2, 3]。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入：</strong>[3,2,1,2,1,7]
<strong>输出：</strong>6
<strong>解释：</strong>经过 6 次 <em>move</em> 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 <em>move</em> 操作是不能让数组的每个值唯一的。
</pre>

<p><strong>提示：</strong></p>

<ol>
	<li><code>0 <= A.length <= 40000</code></li>
	<li><code>0 <= A[i] < 40000</code></li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/945-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minIncrementForUnique(vector<int>& A)
    {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        int ans = 0;
        int st = A[0];
        for (int i = 0; i < A.size(); i++)
        {
            st = max(st, A[i]);
            ans += (A[i] < st) ? st - A[i] : 0;
            st++;
        }
        return ans;
    }
};
```




