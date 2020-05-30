# `（中等）` [5409.check-if-a-string-contains-all-binary-codes-of-size-k 检查一个字符串是否包含所有长度为 K 的二进制子串](https://leetcode-cn.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-27/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)

### 题目描述
<p>给你一个二进制字符串&nbsp;<code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果所有长度为 <code>k</code>&nbsp;的二进制字符串都是 <code>s</code>&nbsp;的子串，请返回 True ，否则请返回 False 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "00110110", k = 2
<strong>输出：</strong>true
<strong>解释：</strong>长度为 2 的二进制串包括 "00"，"01"，"10" 和 "11"。它们分别是 s 中下标为 0，1，3，2 开始的长度为 2 的子串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "00110", k = 2
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "0110", k = 1
<strong>输出：</strong>true
<strong>解释：</strong>长度为 1 的二进制串包括 "0" 和 "1"，显然它们都是 s 的子串。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = "0110", k = 2
<strong>输出：</strong>false
<strong>解释：</strong>长度为 2 的二进制串 "00" 没有出现在 s 中。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>s = "0000000001011100", k = 4
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 5 * 10^5</code></li>
	<li><code>s</code> 中只含 0 和 1 。</li>
	<li><code>1 <= k <= 20</code></li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/solution/check-if-a-string-contains-all-binary-by-ikaruga/)

### 答题
``` C++
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        unordered_set<int> us;
        for (int i = 0; i < s.size() - k + 1; i++) {
            string temp = s.substr(i, k);
            us.insert(stoi(temp, nullptr, 2));
        }

        for (int i = 0; i < (1 << k); i++) {
            if (us.count(i) == 0) return false;
        }
        return true;
    }
```




