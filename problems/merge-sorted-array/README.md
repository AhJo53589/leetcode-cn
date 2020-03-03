# `（简单）` [88.merge-sorted-array 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)

### 题目描述
<p>给定两个有序整数数组&nbsp;<em>nums1 </em>和 <em>nums2</em>，将 <em>nums2 </em>合并到&nbsp;<em>nums1&nbsp;</em>中<em>，</em>使得&nbsp;<em>num1 </em>成为一个有序数组。</p>

<p><strong>说明:</strong></p>

<ul>
	<li>初始化&nbsp;<em>nums1</em> 和 <em>nums2</em> 的元素数量分别为&nbsp;<em>m</em> 和 <em>n</em>。</li>
	<li>你可以假设&nbsp;<em>nums1&nbsp;</em>有足够的空间（空间大小大于或等于&nbsp;<em>m + n</em>）来保存 <em>nums2</em> 中的元素。</li>
</ul>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

<strong>输出:</strong>&nbsp;[1,2,2,3,5,6]</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/merge-sorted-array/solution/88-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = nums1.size() - 1;
        m--;
        n--;
        while (n >= 0)
        {
            while (m >= 0 && nums1[m] > nums2[n])
            {
                swap(nums1[i--], nums1[m--]);
            }
            swap(nums1[i--], nums2[n--]);
        }
    }
};
```




