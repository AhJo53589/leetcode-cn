# `（简单）` [258.add-digits 各位相加](https://leetcode-cn.com/problems/add-digits/)

### 题目描述
<p>给定一个非负整数 <code>num</code>，反复将各个位上的数字相加，直到结果为一位数。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> <code>38</code>
<strong>输出:</strong> 2 
<strong>解释: </strong>各位相加的过程为<strong>：</strong><code>3 + 8 = 11</code>, <code>1 + 1 = 2</code>。 由于&nbsp;<code>2</code> 是一位数，所以返回 2。
</pre>

<p><strong>进阶:</strong><br>
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？</p>


---
### 思路
```
```



### 答题
``` C++
int addDigits(int num) 
{
    if (num == 0) return 0;
    return num % 9 ? num % 9 : 9;
}
```




