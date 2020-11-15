# `（中等）` [5602.minimum-operations-to-reduce-x-to-zero 将 x 减到 0 的最小操作数](https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero/)

[contest](https://leetcode-cn.com/contest/weekly-contest-215/problems/minimum-operations-to-reduce-x-to-zero/)

### 题目描述
<div class="notranslate"><p>给你一个整数数组 <code>nums</code> 和一个整数 <code>x</code> 。每一次操作时，你应当移除数组 <code>nums</code> 最左边或最右边的元素，然后从 <code>x</code> 中减去该元素的值。请注意，需要 <strong>修改</strong> 数组以供接下来的操作使用。</p>

<p>如果可以将 <code>x</code>&nbsp;<strong>恰好</strong> 减到&nbsp;<code>0</code> ，返回<strong> 最小操作数 </strong>；否则，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,4,2,3], x = 5
<strong>输出：</strong>2
<strong>解释：</strong>最佳解决方案是移除后两个元素，将 x 减到 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,6,7,8,9], x = 4
<strong>输出：</strong>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,2,20,1,1,3], x = 10
<strong>输出：</strong>5
<strong>解释：</strong>最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= x &lt;= 10<sup>9</sup></code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero/solution/minimum-operations-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> um;
        int ans = INT_MAX;

        um[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            um[sum] = i;
        }

        sum = 0;
        if (um.find(x) != um.end()) {
            ans = min(ans, um[x] + 1);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            if (um.find(x - sum) != um.end()) {
                int cnt = (int)nums.size() - i + um[x - sum] + 1;
                if (cnt > nums.size()) continue;
                ans = min(ans, cnt);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```




