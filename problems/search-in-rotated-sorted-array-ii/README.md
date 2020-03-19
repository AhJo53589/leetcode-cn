# `（中等）` [81.search-in-rotated-sorted-array-ii 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

### 题目描述
<p>假设按照升序排序的数组在预先未知的某个点上进行了旋转。</p>

<p>( 例如，数组&nbsp;<code>[0,0,1,2,2,5,6]</code>&nbsp;可能变为&nbsp;<code>[2,5,6,0,0,1,2]</code>&nbsp;)。</p>

<p>编写一个函数来判断给定的目标值是否存在于数组中。若存在返回&nbsp;<code>true</code>，否则返回&nbsp;<code>false</code>。</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> nums = [2<code>,5,6,0,0,1,2]</code>, target = 0
<strong>输出:</strong> true
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> nums = [2<code>,5,6,0,0,1,2]</code>, target = 3
<strong>输出:</strong> false</pre>

<p><strong>进阶:</strong></p>

<ul>
	<li>这是 <a href="https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/">搜索旋转排序数组</a>&nbsp;的延伸题目，本题中的&nbsp;<code>nums</code>&nbsp; 可能包含重复元素。</li>
	<li>这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int lowerbound(vector<int>& nums, int target, int low, int high)
{
    while (low < high)
    {
        while (low != high - 1 && nums[low] == nums[high - 1])
        {
            high--;
        }
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (nums[mid] <= nums[high - 1])
        {
            if (nums[mid] <= target && target <= nums[high - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
    }
    return low;
}

bool search(vector<int>& nums, int target)
{
    int ans = lowerbound(nums, target, 0, nums.size());
    return !(ans == nums.size() || nums[ans] != target);
}
```




