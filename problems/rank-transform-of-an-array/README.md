# `（简单）` [1331.rank-transform-of-an-array 将数组进行序号转换](https://leetcode-cn.com/problems/rank-transform-of-an-array/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-18/problems/rank-transform-of-an-array/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>arr</code> ，请你将每个数字用它们排序后的序号替换。</p>

<p>序号代表了一个元素有多大。序号编号的规则如下：</p>

<ul>
	<li>序号从 1 开始编号。</li>
	<li>一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。</li>
	<li>每个数字的序号都应该尽可能地小。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [40,10,20,30]
<strong>输出：</strong>[4,1,2,3]
<strong>解释：</strong>40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [100,100,100]
<strong>输出：</strong>[1,1,1]
<strong>解释：</strong>所有元素有相同的序号。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [37,12,28,9,100,56,80,5,12]
<strong>输出：</strong>[5,3,4,2,8,6,7,1,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
vector<int> arrayRankTransform(vector<int>& arr) 
{
    map<int, int> _map;
    for (auto& n : arr)
    {
        _map[n] = 0;
    }
    int i = 1;
    for (auto& m : _map)
    {
        m.second = i++;
    }
    for (auto& n : arr)
    {
        n = _map[n];
    }
    return arr;
}
```




