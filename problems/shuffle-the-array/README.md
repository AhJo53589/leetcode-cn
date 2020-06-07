# `（简单）` [5428.shuffle-the-array 重新排列数组](https://leetcode-cn.com/problems/shuffle-the-array/)

[contest](https://leetcode-cn.com/contest/weekly-contest-192/problems/shuffle-the-array/)

### 题目描述
<p>给你一个数组 <code>nums</code> ，数组中有 <code>2n</code> 个元素，按 <code>[x<sub>1</sub>,x<sub>2</sub>,...,x<sub>n</sub>,y<sub>1</sub>,y<sub>2</sub>,...,y<sub>n</sub>]</code> 的格式排列。</p>

<p>请你将数组按 <code>[x<sub>1</sub>,y<sub>1</sub>,x<sub>2</sub>,y<sub>2</sub>,...,x<sub>n</sub>,y<sub>n</sub>]</code> 格式重新排列，返回重排后的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,5,1,3,4,7], n = 3
<strong>输出：</strong>[2,3,5,4,1,7] 
<strong>解释：</strong>由于 x<sub>1</sub>=2, x<sub>2</sub>=5, x<sub>3</sub>=1, y<sub>1</sub>=3, y<sub>2</sub>=4, y<sub>3</sub>=7 ，所以答案为 [2,3,5,4,1,7]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,4,3,2,1], n = 4
<strong>输出：</strong>[1,4,2,3,3,2,4,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,2,2], n = 2
<strong>输出：</strong>[1,2,1,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 500</code></li>
	<li><code>nums.length == 2n</code></li>
	<li><code>1 <= nums[i] <= 10^3</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<vector<int>> temp(2, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int t = (i / (nums.size() / 2));
            temp[t].push_back(nums[i]);
        }
        for (int t = 0; t < 2; t++) {
            for (int i = 0; i < temp[t].size(); i++) {
                nums[i * 2] = temp[0][i];
                nums[i * 2 + 1] = temp[1][i];
            }
        }

        return nums;
    }
```




