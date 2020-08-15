# `（简单）` [1534.count-good-triplets 统计好三元组](https://leetcode-cn.com/problems/count-good-triplets/)

[contest](https://leetcode-cn.com/contest/weekly-contest-200/problems/count-good-triplets/)

### 题目描述
<p>给你一个整数数组 <code>arr</code> ，以及 <code>a</code>、<code>b</code> 、<code>c</code> 三个整数。请你统计其中好三元组的数量。</p>

<p>如果三元组 <code>(arr[i], arr[j], arr[k])</code> 满足下列全部条件，则认为它是一个 <strong>好三元组</strong> 。</p>

<ul>
	<li><code>0 <= i < j < k <&nbsp;arr.length</code></li>
	<li><code>|arr[i] - arr[j]| <= a</code></li>
	<li><code>|arr[j] - arr[k]| <= b</code></li>
	<li><code>|arr[i] - arr[k]| <= c</code></li>
</ul>

<p>其中 <code>|x|</code> 表示 <code>x</code> 的绝对值。</p>

<p>返回 <strong>好三元组的数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
<strong>输出：</strong>4
<strong>解释：</strong>一共有 4 个好三元组：[(3,0,1), (3,0,1), (3,1,1), (0,1,1)] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,1,2,2,3], a = 0, b = 0, c = 1
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足所有条件的三元组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= arr.length <= 100</code></li>
	<li><code>0 <= arr[i] <= 1000</code></li>
	<li><code>0 <= a, b, c <= 1000</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                for (int k = j + 1; k < arr.size(); k++) {
                    ans += (abs(arr[i] - arr[j]) <= a) && (abs(arr[j] - arr[k]) <= b) && (abs(arr[i] - arr[k]) <= c);
                }
            }
        }
        return ans;
    }
};
```




