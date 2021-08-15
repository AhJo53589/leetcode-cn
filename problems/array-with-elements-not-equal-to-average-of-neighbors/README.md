# `（中等）` [5832.array-with-elements-not-equal-to-average-of-neighbors 构造元素不等于两相邻元素平均值的数组](https://leetcode-cn.com/problems/array-with-elements-not-equal-to-average-of-neighbors/)

[contest](https://leetcode-cn.com/contest/weekly-contest-254/problems/array-with-elements-not-equal-to-average-of-neighbors/)

### 题目描述
<div class="notranslate"><p>给你一个 <strong>下标从 0 开始</strong> 的数组 <code>nums</code> ，数组由若干 <strong>互不相同的</strong> 整数组成。你打算重新排列数组中的元素以满足：重排后，数组中的每个元素都 <strong>不等于</strong> 其两侧相邻元素的 <strong>平均值</strong> 。</p>

<p>更公式化的说法是，重新排列的数组应当满足这一属性：对于范围&nbsp;<code>1 &lt;= i &lt; nums.length - 1</code> 中的每个 <code>i</code> ，<code>(nums[i-1] + nums[i+1]) / 2</code> <strong>不等于</strong> <code>nums[i]</code> 均成立 。</p>

<p>返回满足题意的任一重排结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5]
<strong>输出：</strong>[1,2,4,5,3]
<strong>解释：</strong>
i=1, nums[i] = 2, 两相邻元素平均值为 (1+4) / 2 = 2.5
i=2, nums[i] = 4, 两相邻元素平均值为 (2+5) / 2 = 3.5
i=3, nums[i] = 5, 两相邻元素平均值为 (4+3) / 2 = 3.5
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [6,2,0,9,7]
<strong>输出：</strong>[9,7,6,2,0]
<strong>解释：</strong>
i=1, nums[i] = 7, 两相邻元素平均值为 (9+6) / 2 = 7.5
i=2, nums[i] = 6, 两相邻元素平均值为 (7+2) / 2 = 4.5
i=3, nums[i] = 2, 两相邻元素平均值为 (6+0) / 2 = 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            swap(nums[0], nums[i]);
            if (dfs(0, nums)) break;
        }
        return nums;
    }

    bool dfs(int idx, vector<int>& nums) {
        if (idx == nums.size()) return true;

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            if (idx < 2 || nums[idx - 1] * 2 != nums[idx - 2] + nums[idx]) {
                if (dfs(idx + 1, nums)) return true;
            }
            swap(nums[i], nums[idx]);
        }
        return false;
    }
};
```




