# `（中等）` [338.counting-bits 比特位计数](https://leetcode-cn.com/problems/counting-bits/)

### 题目描述
<p>给定一个非负整数&nbsp;<strong>num</strong>。对于&nbsp;<strong>0 ≤ i ≤ num </strong>范围中的每个数字&nbsp;<strong>i&nbsp;</strong>，计算其二进制数中的 1 的数目并将它们作为数组返回。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>2
<strong>输出: </strong>[0,1,1]</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入: </strong>5
<strong>输出: </strong><code>[0,1,1,2,1,2]</code></pre>

<p><strong>进阶:</strong></p>

<ul>
	<li>给出时间复杂度为<strong>O(n*sizeof(integer))</strong>的解答非常容易。但你可以在线性时间<strong>O(n)</strong>内用一趟扫描做到吗？</li>
	<li>要求算法的空间复杂度为<strong>O(n)</strong>。</li>
	<li>你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的&nbsp;<strong>__builtin_popcount</strong>）来执行此操作。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/counting-bits/solution/counting-bits-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        ans[0] = 0;
        if (num == 0) return ans;
        ans[1] = 1;
        if (num == 1) return ans;

        int k = 2;
        for (int i = k; i < ans.size(); i++) {
            k *= (i == k + k) ? 2 : 1;
            ans[i] = 1 + ans[i - k];
        }

        return ans;
    }
};
```




