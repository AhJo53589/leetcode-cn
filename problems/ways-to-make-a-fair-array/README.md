# `（中等）` [1664.ways-to-make-a-fair-array 生成平衡数组的方案数](https://leetcode-cn.com/problems/ways-to-make-a-fair-array/)

[contest](https://leetcode-cn.com/contest/weekly-contest-216/problems/ways-to-make-a-fair-array/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。你需要选择 <strong>恰好</strong>&nbsp;一个下标（下标从 <strong>0</strong>&nbsp;开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。</p>

<p>比方说，如果&nbsp;<code>nums = [6,1,7,4,1]</code>&nbsp;，那么：</p>

<ul>
	<li>选择删除下标 <code>1</code> ，剩下的数组为&nbsp;<code>nums = [6,7,4,1]</code>&nbsp;。</li>
	<li>选择删除下标&nbsp;<code>2</code>&nbsp;，剩下的数组为&nbsp;<code>nums = [6,1,4,1]</code>&nbsp;。</li>
	<li>选择删除下标&nbsp;<code>4</code>&nbsp;，剩下的数组为&nbsp;<code>nums = [6,1,7,4]</code>&nbsp;。</li>
</ul>

<p>如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 <strong>平衡数组</strong> 。</p>

<p>请你返回删除操作后，剩下的数组<em>&nbsp;</em><code>nums</code><em>&nbsp;</em>是&nbsp;<strong>平衡数组</strong> 的&nbsp;<strong>方案数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,1,6,4]
<b>输出：</b>1
<strong>解释：</strong>
删除下标 0 ：[1,6,4] -&gt; 偶数元素下标为：1 + 4 = 5 。奇数元素下标为：6 。不平衡。
删除下标 1 ：[2,6,4] -&gt; 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：6 。平衡。
删除下标 2 ：[2,1,4] -&gt; 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：1 。不平衡。
删除下标 3 ：[2,1,6] -&gt; 偶数元素下标为：2 + 6 = 8 。奇数元素下标为：1 。不平衡。
只有一种让剩余数组成为平衡数组的方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,1,1]
<b>输出：</b>3
<b>解释：</b>你可以删除任意元素，剩余数组都是平衡数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,2,3]
<b>输出：</b>0
<b>解释：</b>不管删除哪个元素，剩下数组都不是平衡数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> frt(nums.size(), 0);
        vector<int> bck(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            frt[i] = (i == 0) ? sum : sum - frt[i - 1];
            // cout << frt[i] << ", ";
        }
        // cout << endl;
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            bck[i] = (i == nums.size() - 1) ? sum : sum - bck[i + 1];
            // cout << bck[i] << ", ";
        }
        // cout << endl;
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int f_0 = (i % 2 == 0) ? i - 2 : i - 1;
            int f_1 = (i % 2 == 0) ? i - 1 : i - 2;
            int sum_0 = (f_0 < 0) ? 0 : frt[f_0];
            int sum_1 = (f_1 < 0) ? 0 : frt[f_1];
            
            int b_0 = (i % 2 == 0) ? i + 1 : i + 2;
            int b_1 = (i % 2 == 0) ? i + 2 : i + 1;
            sum_0 += (b_0 > nums.size() - 1) ? 0 : bck[b_0];
            sum_1 += (b_1 > nums.size() - 1) ? 0 : bck[b_1];
            
            // cout << sum_0 << ", " << sum_1 << endl;
            ans += (sum_0 == sum_1);
        }
        return ans;
    }
};
```




