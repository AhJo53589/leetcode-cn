# `（中等）` [5281.find-the-smallest-divisor-given-a-threshold 使结果不超过阈值的最小除数](https://leetcode-cn.com/problems/find-the-smallest-divisor-given-a-threshold/)

[contest](https://leetcode-cn.com/contest/weekly-contest-166/problems/find-the-smallest-divisor-given-a-threshold/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>nums</code> 和一个正整数&nbsp;<code>threshold</code> &nbsp;，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。</p>

<p>请你找出能够使上述结果小于等于阈值&nbsp;<code>threshold</code>&nbsp;的除数中 <strong>最小</strong> 的那个。</p>

<p>每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。</p>

<p>题目保证一定有解。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,5,9], threshold = 6
<strong>输出：</strong>5
<strong>解释：</strong>如果除数为 1 ，我们可以得到和为 17 （1+2+5+9）。
如果除数为 4 ，我们可以得到和为 7 (1+1+2+3) 。如果除数为 5 ，和为 5 (1+1+1+2)。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,5,7,11], threshold = 11
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [19], threshold = 5
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^6</code></li>
	<li><code>nums.length &lt;=&nbsp;threshold &lt;= 10^6</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int getSum(vector<int>& nums, int d)
{
    int ans = 0;
    for (auto n : nums)
    {
        ans += n / d + ((n % d) != 0);
    }
    return ans;
}

int smallestDivisor(vector<int>& nums, int threshold) 
{
    int left = 1;
    int right = 1;
    for (auto n : nums)
    {
        right = max(right, n);
    }

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (getSum(nums, mid) > threshold)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
```




