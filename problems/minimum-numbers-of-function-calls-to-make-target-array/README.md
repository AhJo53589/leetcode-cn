# `（中等）` [5481.minimum-numbers-of-function-calls-to-make-target-array 得到目标数组的最少函数调用次数](https://leetcode-cn.com/problems/minimum-numbers-of-function-calls-to-make-target-array/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-33/problems/minimum-numbers-of-function-calls-to-make-target-array/)

### 题目描述
<p><img style="height:294px; width:573px" src="https://assets.leetcode.com/uploads/2020/07/10/sample_2_1887.png" alt=""></p>

<p>给你一个与 <code>nums</code>&nbsp;大小相同且初始值全为 0 的数组 <code>arr</code> ，请你调用以上函数得到整数数组 <code>nums</code>&nbsp;。</p>

<p>请你返回将 <code>arr</code>&nbsp;变成 <code>nums</code>&nbsp;的最少函数调用次数。</p>

<p>答案保证在 32 位有符号整数以内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,5]
<strong>输出：</strong>5
<strong>解释：</strong>给第二个数加 1 ：[0, 0] 变成 [0, 1] （1 次操作）。
将所有数字乘以 2 ：[0, 1] -> [0, 2] -> [0, 4] （2 次操作）。
给两个数字都加 1 ：[0, 4] -> [1, 4] -> <strong>[1, 5]</strong> （2 次操作）。
总操作次数为：1 + 2 + 2 = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [2,2]
<strong>输出：</strong>3
<strong>解释：</strong>给两个数字都加 1 ：[0, 0] -> [0, 1] -> [1, 1] （2 次操作）。
将所有数字乘以 2 ： [1, 1] -> <strong>[2, 2]</strong> （1 次操作）。
总操作次数为： 2 + 1 = 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [4,2,5]
<strong>输出：</strong>6
<strong>解释：</strong>（初始）[0,0,0] -> [1,0,0] -> [1,0,1] -> [2,0,2] -> [2,1,2] -> [4,2,4] -> <strong>[4,2,5] </strong>（nums 数组）。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [3,2,2,4]
<strong>输出：</strong>7
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>nums = [2,4,8,16]
<strong>输出：</strong>8
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10^5</code></li>
	<li><code>0 <= nums[i] <= 10^9</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-numbers-of-function-calls-to-make-target-array/solution/minimum-numbers-of-function-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (auto n : nums) {
            auto [f, s] = calc(n);
            a += f;
            b = max(b, s);
        }
        return a + b;
    }

    pair<int, int> calc(int n) {
        if (n == 0) return { 0, 0 };
        int a = 0;
        int b = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                a++;
                n--;
            }
            else {
                b++;
                n /= 2;
            }
        }
        return { a, b };
    }
};

```




