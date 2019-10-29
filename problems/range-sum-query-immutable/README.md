# `（简单）` [303.range-sum-query-immutable 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)

### 题目描述
<p>给定一个整数数组 &nbsp;<em>nums</em>，求出数组从索引&nbsp;<em>i&nbsp;</em>到&nbsp;<em>j&nbsp;&nbsp;</em>(<em>i</em>&nbsp;≤&nbsp;<em>j</em>) 范围内元素的总和，包含&nbsp;<em>i,&nbsp; j&nbsp;</em>两点。</p>

<p><strong>示例：</strong></p>

<pre>给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -&gt; 1
sumRange(2, 5) -&gt; -1
sumRange(0, 5) -&gt; -3</pre>

<p><strong>说明:</strong></p>

<ol>
	<li>你可以假设数组不可变。</li>
	<li>会多次调用&nbsp;<em>sumRange</em>&nbsp;方法。</li>
</ol>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/range-sum-query-immutable/solution/303-by-ikaruga/)

### 答题
``` C++
class NumArray {
public:
    NumArray(vector<int>& nums) : m_nums(nums)
    {
        partial_sum(m_nums.begin(), m_nums.end(), back_inserter(m_partial));
    }
    
    int sumRange(int i, int j) 
    {
        return m_partial[j] - m_partial[i] + m_nums[i];
    }
    
private:
    vector<int> m_nums;
    vector<int> m_partial;
};
```




