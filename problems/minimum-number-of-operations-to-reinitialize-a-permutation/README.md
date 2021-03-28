# `（中等）` [5715.minimum-number-of-operations-to-reinitialize-a-permutation 还原排列的最少操作步数](https://leetcode-cn.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/)

[contest](https://leetcode-cn.com/contest/weekly-contest-234/problems/minimum-number-of-operations-to-reinitialize-a-permutation/)

### 题目描述
<p>给你一个偶数 <code>n</code>​​​​​​ ，已知存在一个长度为 <code>n</code> 的排列 <code>perm</code> ，其中 <code>perm[i] == i</code>​（下标 <strong>从 0 开始</strong> 计数）。</p>

<p>一步操作中，你将创建一个新数组 <code>arr</code> ，对于每个 <code>i</code> ：</p>

<ul>
	<li>如果 <code>i % 2 == 0</code> ，那么 <code>arr[i] = perm[i / 2]</code></li>
	<li>如果 <code>i % 2 == 1</code> ，那么 <code>arr[i] = perm[n / 2 + (i - 1) / 2]</code></li>
</ul>

<p>然后将 <code>arr</code>​​ 赋值​​给 <code>perm</code> 。</p>

<p>要想使 <code>perm</code> 回到排列初始值，至少需要执行多少步操作？返回最小的 <strong>非零</strong> 操作步数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>1
<strong>解释：</strong>最初，perm = [0,1]
第 1&nbsp;步操作后，perm = [0,1]
所以，仅需执行 1 步操作</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>2
<strong>解释：</strong>最初，perm = [0,1,2,3]
第 1&nbsp;步操作后，perm = [0,2,1,3]
第 2&nbsp;步操作后，perm = [0,1,2,3]
所以，仅需执行 2 步操作</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 6
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>n</code>​​​​​​ 是一个偶数</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for (int i = 0; i < perm.size(); i++) {
            perm[i] = i;
        }
        vector<int> def = perm;

        int ans = 0;
        vector<int> arr(perm.size());
        while (ans == 0 || perm != def) {
            for (int i = 0; i < perm.size(); i++) {
                if (i % 2 == 0) {
                    arr[i] = perm[i / 2];
                }
                else {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            perm = arr;
            ans++;
        }
        return ans;
    }
};
```




