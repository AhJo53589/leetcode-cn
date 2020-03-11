# `（简单）` [1013.partition-array-into-three-parts-with-equal-sum 将数组分成和相等的三个部分](https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>A</code>，只有可以将其划分为三个和相等的非空部分时才返回&nbsp;<code>true</code>，否则返回 <code>false</code>。</p>

<p>形式上，如果可以找出索引&nbsp;<code>i+1 < j</code>&nbsp;且满足&nbsp;<code>(A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])</code>&nbsp;就可以将数组三等分。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输出：</strong>[0,2,1,-6,6,-7,9,1,2,0,1]
<strong>输出：</strong>true
<strong>解释：</strong>0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>[0,2,1,-6,6,7,9,-1,2,0,1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>[3,3,6,5,-2,2,5,1,-9,4]
<strong>输出：</strong>true
<strong>解释：</strong>3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>3 <= A.length <= 50000</code></li>
	<li><code>-10^4&nbsp;<= A[i] <= 10^4</code></li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A)
	{
		int sum = accumulate(A.begin(), A.end(), 0);
		if (sum % 3 != 0) return false;
		int avg = sum / 3;
		sum = 0;
		int ans = 0;
		for (auto& n : A)
		{
			sum += n;
			ans += (avg == sum);
			sum = (avg == sum) ? 0 : sum;
		}
		return ans >= 3;
    }
};
```




