# `（简单）` [228.summary-ranges 汇总区间](https://leetcode-cn.com/problems/summary-ranges/)

### 题目描述
<p>给定一个无重复元素的有序整数数组 <code>nums</code> 。</p>

<p>返回 <strong>恰好覆盖数组中所有数字</strong> 的 <strong>最小有序</strong> 区间范围列表。也就是说，<code>nums</code> 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 <code>nums</code> 的数字 <code>x</code> 。</p>

<p>列表中的每个区间范围 <code>[a,b]</code> 应该按如下格式输出：</p>

<ul>
	<li><code>"a-&gt;b"</code> ，如果 <code>a != b</code></li>
	<li><code>"a"</code> ，如果 <code>a == b</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,2,4,5,7]
<strong>输出：</strong>["0-&gt;2","4-&gt;5","7"]
<strong>解释：</strong>区间范围是：
[0,2] --&gt; "0-&gt;2"
[4,5] --&gt; "4-&gt;5"
[7,7] --&gt; "7"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0,2,3,4,6,8,9]
<strong>输出：</strong>["0","2-&gt;4","6","8-&gt;9"]
<strong>解释：</strong>区间范围是：
[0,0] --&gt; "0"
[2,4] --&gt; "2-&gt;4"
[6,6] --&gt; "6"
[8,9] --&gt; "8-&gt;9"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums = [-1]
<strong>输出：</strong>["-1"]
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>nums = [0]
<strong>输出：</strong>["0"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 20</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>nums</code> 中的所有值都 <strong>互不相同</strong></li>
	<li><code>nums</code> 按升序排列</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(INT_MIN);
        vector<string> ans;
        int left = 0; 
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && 1LL * nums[i] != 1LL * nums[i - 1] + 1) {
                if (left == i - 1) {
                    ans.push_back(to_string(nums[i - 1]));
                }
                else {
                    ans.push_back(to_string(nums[left]) + "->" + to_string(nums[i - 1]));
                }
                left = i;
            }
        }
        return ans;
    }
};
```




