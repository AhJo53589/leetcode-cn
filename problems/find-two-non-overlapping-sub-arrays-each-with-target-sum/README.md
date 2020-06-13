# `（中等）` [5423.find-two-non-overlapping-sub-arrays-each-with-target-sum 找两个和为目标值且不重叠的子数组](https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-28/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>arr</code> 和一个整数值&nbsp;<code>target</code>&nbsp;。</p>

<p>请你在 <code>arr</code>&nbsp;中找 <strong>两个互不重叠的子数组</strong>&nbsp;且它们的和都等于&nbsp;<code>target</code>&nbsp;。可能会有多种方案，请你返回满足要求的两个子数组长度和的 <strong>最小值</strong> 。</p>

<p>请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 <strong>-1</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,2,2,4,3], target = 3
<strong>输出：</strong>2
<strong>解释：</strong>只有两个子数组和为 3 （[3] 和 [3]）。它们的长度和为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [7,3,4,7], target = 7
<strong>输出：</strong>2
<strong>解释：</strong>尽管我们有 3 个互不重叠的子数组和为 7 （[7], [3,4] 和 [7]），但我们会选择第一个和第三个子数组，因为它们的长度和 2 是最小值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [4,3,2,6,2,3,4], target = 6
<strong>输出：</strong>-1
<strong>解释：</strong>我们只有一个和为 6 的子数组。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [5,5,4,4,5], target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>我们无法找到和为 3 的子数组。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [3,1,1,1,5,1,2,1], target = 3
<strong>输出：</strong>3
<strong>解释：</strong>注意子数组 [1,2] 和 [2,1] 不能成为一个方案因为它们重叠了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10^5</code></li>
	<li><code>1 <= arr[i] <= 1000</code></li>
	<li><code>1 <= target <= 10^8</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/solution/find-two-by-ikaruga/)

### 答题
``` C++
    int minSumOfLengths(vector<int>& arr, int target) {
        multimap<int, int> rec;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < arr.size()) {
            sum += arr[right];
            right++;
            if (sum < target) continue;
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                rec.insert({ right - left, left });
            }
        }

        int ans = INT_MAX;
        for (auto r1 = rec.begin(); r1 != rec.end(); r1++) {
            if (r1->first * 2 >= ans) break;
            auto r2 = r1;
            while ((++r2) != rec.end()) {
                if (r1->second < r2->second && r1->second + r1->first > r2->second) continue;
                if (r2->second < r1->second && r2->second + r2->first > r1->second) continue;
                ans = min(ans, r1->first + r2->first);
                break;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
```




