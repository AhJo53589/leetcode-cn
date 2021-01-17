# `（中等）` [5243.tuple-with-same-product 同积元组](https://leetcode-cn.com/problems/tuple-with-same-product/)

[contest](https://leetcode-cn.com/contest/weekly-contest-224/problems/tuple-with-same-product/)

### 题目描述
<div class="notranslate"><p>给你一个由 <strong>不同</strong> 正整数组成的数组 <code>nums</code> ，请你返回满足&nbsp;<code>a * b = c * d</code> 的元组<em> </em><code>(a, b, c, d)</code><em> </em>的数量。其中 <code>a</code>、<code>b</code>、<code>c</code> 和 <code>d</code> 都是 <code>nums</code> 中的元素，且 <code>a != b != c != d</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,4,6]
<strong>输出：</strong>8
<strong>解释：</strong>存在 8 个满足题意的元组：
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (3,4,2,6) , (3,4,6,2) , (4,3,6,2)
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,4,5,10]
<strong>输出：</strong>16
<strong>解释：</strong>存在 16 个满足题意的元组：
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,4,6,8,12]
<strong>输出：</strong>40
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,5,7]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 中的所有元素 <strong>互不相同</strong></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/tuple-with-same-product/solution/problemstuple-with-same-product-by-ikaru-5vs9/)

### 答题
``` C++
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                dic[nums[i] * nums[j]]++;
            }
        }
        for (auto [k, v] : dic) {
            if (v < 2) continue;
            ans += combi(v, 2);
        }
        return ans * 8;
    }

    long long combi(int n, int m) {
        long long ans = 1;
        m = (m > n - m) ? n - m : m;
        for (int i = 0; i < m; i++) {
            ans *= n - i;
            ans /= i + 1;
        }
        return ans;
    }
};
```




