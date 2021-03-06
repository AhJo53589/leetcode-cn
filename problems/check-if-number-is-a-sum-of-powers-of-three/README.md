# `（中等）` [5681.check-if-number-is-a-sum-of-powers-of-three 判断一个数字是否可以表示成三的幂的和](https://leetcode-cn.com/problems/check-if-number-is-a-sum-of-powers-of-three/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-47/problems/check-if-number-is-a-sum-of-powers-of-three/)

### 题目描述
<div class="notranslate"><p>一个字符串的 <strong>美丽值</strong>&nbsp;定义为：出现频率最高字符与出现频率最低字符的出现次数之差。</p>

<ul>
	<li>比方说，<code>"abaacc"</code>&nbsp;的美丽值为&nbsp;<code>3 - 1 = 2</code>&nbsp;。</li>
</ul>

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，请你返回它所有子字符串的&nbsp;<strong>美丽值</strong>&nbsp;之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "aabcb"
<b>输出：</b>5
<strong>解释：</strong>美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "aabcbaa"
<b>输出：</b>17
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;=<sup> </sup>500</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool checkPowersOfThree(int n) {
        for (; n; n /= 3) {
            if (n % 3 == 2) return false;
        }
        return true;
    }
};
```




