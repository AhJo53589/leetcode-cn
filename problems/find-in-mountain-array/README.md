# `（困难）` [1095.find-in-mountain-array 山脉数组中查找目标值](https://leetcode-cn.com/problems/find-in-mountain-array/)

### 题目描述
<p>（这是一个 <strong>交互式问题&nbsp;</strong>）</p>

<p>给你一个 <strong>山脉数组</strong>&nbsp;<code>mountainArr</code>，请你返回能够使得&nbsp;<code>mountainArr.get(index)</code>&nbsp;<strong>等于</strong>&nbsp;<code>target</code>&nbsp;<strong>最小</strong>&nbsp;的下标 <code>index</code>&nbsp;值。</p>

<p>如果不存在这样的下标 <code>index</code>，就请返回&nbsp;<code>-1</code>。</p>

<p>&nbsp;</p>

<p>何为山脉数组？如果数组&nbsp;<code>A</code> 是一个山脉数组的话，那它满足如下条件：</p>

<p><strong>首先</strong>，<code>A.length >= 3</code></p>

<p><strong>其次</strong>，在&nbsp;<code>0 < i&nbsp;< A.length - 1</code>&nbsp;条件下，存在 <code>i</code> 使得：</p>

<ul>
	<li><code>A[0] < A[1] < ... A[i-1] < A[i]</code></li>
	<li><code>A[i] > A[i+1] > ... > A[A.length - 1]</code></li>
</ul>

<p>&nbsp;</p>

<p>你将&nbsp;<strong>不能直接访问该山脉数组</strong>，必须通过&nbsp;<code>MountainArray</code>&nbsp;接口来获取数据：</p>

<ul>
	<li><code>MountainArray.get(k)</code>&nbsp;- 会返回数组中索引为<code>k</code>&nbsp;的元素（下标从 0 开始）</li>
	<li><code>MountainArray.length()</code>&nbsp;- 会返回该数组的长度</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<p>对&nbsp;<code>MountainArray.get</code>&nbsp;发起超过 <code>100</code> 次调用的提交将被视为错误答案。此外，任何试图规避判题系统的解决方案都将会导致比赛资格被取消。</p>

<p>为了帮助大家更好地理解交互式问题，我们准备了一个样例 “<strong>答案</strong>”：<a href="https://leetcode-cn.com/playground/RKhe3ave">https://leetcode-cn.com/playground/RKhe3ave</a>，请注意这 <strong>不是一个正确答案</strong>。</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>array = [1,2,3,4,5,3,1], target = 3
<strong>输出：</strong>2
<strong>解释：</strong>3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>array = [0,1,2,4,2,1], target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>3 在数组中没有出现，返回 -1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= mountain_arr.length() <= 10000</code></li>
	<li><code>0 <= target <= 10^9</code></li>
	<li><code>0 <= mountain_arr.get(index) <=&nbsp;10^9</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int binary_search(MountainArray& mountain, int target, int l, int r, int key(int)) {
        target = key(target);
        while (l <= r) {
            int mid = (l + r) / 2;
            int cur = key(mountain.get(mid));
            if (cur == target)
                return mid;
            else if (cur < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        int peak = l;
        int index = binary_search(mountainArr, target, 0, peak, [](int x) -> int {return x; });
        if (index != -1)
            return index;
        return binary_search(mountainArr, target, peak + 1, mountainArr.length() - 1, [](int x) -> int {return -x; });
    }
};
```




