# `（中等）` [5939.k-radius-subarray-averages 半径为 k 的子数组平均值](https://leetcode-cn.com/problems/k-radius-subarray-averages/)

[contest](https://leetcode-cn.com/contest/weekly-contest-269/problems/k-radius-subarray-averages/)

### 题目描述
<div class="notranslate"><p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组中有 <code>n</code> 个整数，另给你一个整数 <code>k</code> 。</p>

<p><strong>半径为 k 的子数组平均值</strong> 是指：<code>nums</code> 中一个以下标 <code>i</code> 为 <strong>中心</strong> 且 <strong>半径</strong> 为 <code>k</code> 的子数组中所有元素的平均值，即下标在&nbsp;<code>i - k</code> 和 <code>i + k</code> 范围（<strong>含</strong> <code>i - k</code> 和 <code>i + k</code>）内所有元素的平均值。如果在下标 <code>i</code> 前或后不足 <code>k</code> 个元素，那么<strong> 半径为 k 的子数组平均值 </strong>是 <code>-1</code> 。</p>

<p>构建并返回一个长度为 <code>n</code> 的数组<em> </em><code>avgs</code><em> </em>，其中<em> </em><code>avgs[i]</code><em> </em>是以下标 <code>i</code> 为中心的子数组的<strong> 半径为 k 的子数组平均值 </strong>。</p>

<p><code>x</code> 个元素的 <strong>平均值</strong> 是 <code>x</code> 个元素相加之和除以 <code>x</code> ，此时使用截断式 <strong>整数除法</strong> ，即需要去掉结果的小数部分。</p>

<ul>
	<li>例如，四个元素 <code>2</code>、<code>3</code>、<code>1</code> 和 <code>5</code> 的平均值是 <code>(2 + 3 + 1 + 5) / 4 = 11 / 4 = 3.75</code>，截断后得到 <code>3</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 343px; height: 119px;" src="https://assets.leetcode.com/uploads/2021/11/07/eg1.png" alt=""></p>

<pre><strong>输入：</strong>nums = [7,4,3,9,1,8,5,2,6], k = 3
<strong>输出：</strong>[-1,-1,-1,5,4,4,-1,-1,-1]
<strong>解释：</strong>
- avg[0]、avg[1] 和 avg[2] 是 -1 ，因为在这几个下标前的元素数量都不足 k 个。
- 中心为下标 3 且半径为 3 的子数组的元素总和是：7 + 4 + 3 + 9 + 1 + 8 + 5 = 37 。
  使用截断式 <strong>整数除法</strong>，avg[3] = 37 / 7 = 5 。
- 中心为下标 4 的子数组，avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4 。
- 中心为下标 5 的子数组，avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4 。
- avg[6]、avg[7] 和 avg[8] 是 -1 ，因为在这几个下标后的元素数量都不足 k 个。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [100000], k = 0
<strong>输出：</strong>[100000]
<strong>解释：</strong>
- 中心为下标 0 且半径 0 的子数组的元素总和是：100000 。
  avg[0] = 100000 / 1 = 100000 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [8], k = 100000
<strong>输出：</strong>[-1]
<strong>解释：</strong>
- avg[0] 是 -1 ，因为在下标 0 前后的元素数量均不足 k 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i], k &lt;= 10<sup>5</sup></code></li>
</ul>
</div>

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/k-radius-subarray-averages/solution/k-radius-subarray-averages-by-ikaruga-52ic/)

### 答题
``` C++
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long long> lnums(nums.begin(), nums.end());
        vector<long long> ps(1, 0);
        partial_sum(lnums.begin(), lnums.end(), back_inserter(ps));

        vector<int> ans(nums.size(), -1);
        for (int i = k; i < (int)nums.size() - k; i++) {
            int avg = (ps[i + k + 1] - ps[i - k]) / (2 * k + 1);
            ans[i] = avg;
        }
        return ans;
    }
};
```




