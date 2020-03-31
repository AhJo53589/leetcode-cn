# `（中等）` [912.sort-an-array 排序数组](https://leetcode-cn.com/problems/sort-an-array/)

### 题目描述
<p>给定一个整数数组&nbsp;<code>nums</code>，将该数组升序排列。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>[5,2,3,1]
<strong>输出：</strong>[1,2,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[5,1,1,2,0,0]
<strong>输出：</strong>[0,0,1,1,2,5]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 <= A.length <= 10000</code></li>
	<li><code>-50000 <= A[i] <= 50000</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int parttion(vector<int>& nums, int l, int r)
    {
        int m = l;
        for (int i = l; i < r; i++)
        {
            if (nums[i] < nums[r])
            {
                swap(nums[m++], nums[i]);
            }
        }
        swap(nums[m], nums[r]);
        return m;
    }

    void quicksort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int m = parttion(nums, l, r);
        quicksort(nums, l, m - 1);
        quicksort(nums, m + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};
```




