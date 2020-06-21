# `（简单）` [1464.maximum-product-of-two-elements-in-an-array 数组中两元素的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-two-elements-in-an-array/)

[contest](https://leetcode-cn.com/contest/weekly-contest-191/problems/maximum-product-of-two-elements-in-an-array/)

### 题目描述
<p>给你一个整数数组 <code>nums</code>，请你选择数组的两个不同下标 <code>i</code> 和 <code>j</code><em>，</em>使 <code>(nums[i]-1)*(nums[j]-1)</code> 取得最大值。</p>

<p>请你计算并返回该式的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,5,2]
<strong>输出：</strong>12 
<strong>解释：</strong>如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,5,4,5]
<strong>输出：</strong>16
<strong>解释：</strong>选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,7]
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= nums.length <= 500</code></li>
	<li><code>1 <= nums[i] <= 10^3</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
    int maxProduct(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        if (a < b) {
            swap(a, b);
        }

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] >= a) {
                b = a;
                a = nums[i];
            }
            else if (nums[i] >= b) {
                b = nums[i];
            }
        }

        return (a - 1) * (b - 1);
    }
```




