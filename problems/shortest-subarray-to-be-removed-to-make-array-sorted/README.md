# `（中等）` [1574.shortest-subarray-to-be-removed-to-make-array-sorted 删除最短的子数组使剩余数组有序](https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-34/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)

### 题目描述
<p>给你一个整数数组 <code>arr</code>&nbsp;，请你删除一个子数组（可以为空），使得 <code>arr</code>&nbsp;中剩下的元素是 <strong>非递减</strong> 的。</p>

<p>一个子数组指的是原数组中连续的一个子序列。</p>

<p>请你返回满足题目要求的最短子数组的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3,10,4,2,3,5]
<strong>输出：</strong>3
<strong>解释：</strong>我们需要删除的最短子数组是 [10,4,2] ，长度为 3 。剩余元素形成非递减数组 [1,2,3,3,5] 。
另一个正确的解为删除子数组 [3,10,4] 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [5,4,3,2,1]
<strong>输出：</strong>4
<strong>解释：</strong>由于数组是严格递减的，我们只能保留一个元素。所以我们需要删除长度为 4 的子数组，要么删除 [5,4,3,2]，要么删除 [4,3,2,1]。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>数组已经是非递减的了，我们不需要删除任何元素。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^9</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solution/shortest-subarray-to-be-removed-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int f = arr.size() - 1;
        int b = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1]) continue;
            f = i - 1;
            break;
        }
        for (int i = arr.size() - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) continue;
            b = i + 1;
            break;
        }
        if (f == arr.size() - 1) return 0;
        
        int ans = arr.size() - 1;
        for (int i = f; i >= 0; i--) {
            if (b - i - 1 >= ans) break;
            for (int j = b; j < arr.size(); j++) {
                if (j - i - 1 >= ans) break;
                if (arr[i] <= arr[j]) {
                    ans = min(ans, j - i - 1);
                }
            }
        }
        //if (f + 1 == b) {   
            ans = min(ans, (int)arr.size() - f - 1);
            ans = min(ans, b);
        //}
        
        return ans;
        
    }
};
```




