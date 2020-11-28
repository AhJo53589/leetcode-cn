# `（困难）` [493.reverse-pairs 翻转对](https://leetcode-cn.com/problems/reverse-pairs/)

### 题目描述
<p>给定一个数组&nbsp;<code>nums</code>&nbsp;，如果&nbsp;<code>i < j</code>&nbsp;且&nbsp;<code>nums[i] > 2*nums[j]</code>&nbsp;我们就将&nbsp;<code>(i, j)</code>&nbsp;称作一个<strong><em>重要翻转对</em></strong>。</p>

<p>你需要返回给定数组中的重要翻转对的数量。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入</strong>: [1,3,2,3,1]
<strong>输出</strong>: 2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入</strong>: [2,4,3,5,1]
<strong>输出</strong>: 3
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>给定数组的长度不会超过<code>50000</code>。</li>
	<li>输入数组中的所有数字都在32位整数的表示范围内。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int reversePairsRecursive(vector<int>& nums, int left, int right) {
        if (left == right) return 0;
            
        int mid = (left + right) / 2;
        int n1 = reversePairsRecursive(nums, left, mid);
        int n2 = reversePairsRecursive(nums, mid + 1, right);
        int ret = n1 + n2;

        // 首先统计下标对的数量
        int i = left;
        int j = mid + 1;
        while (i <= mid) {
            while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) j++;
            ret += (j - mid - 1);
            i++;
        }

        // 随后合并两个排序数组
        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;        
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) {
                sorted[p++] = nums[p2++];
            } else if (p2 > right) {
                sorted[p++] = nums[p1++];
            } else {
                if (nums[p1] < nums[p2]) {
                    sorted[p++] = nums[p1++];
                } else {
                    sorted[p++] = nums[p2++];
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            nums[left + i] = sorted[i];
        }

        return ret;
    }

    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return reversePairsRecursive(nums, 0, nums.size() - 1);
    }
};
```




