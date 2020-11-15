# `（中等）` [402.remove-k-digits 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/)

### 题目描述
<p>给定一个以字符串表示的非负整数&nbsp;<em>num</em>，移除这个数中的 <em>k </em>位数字，使得剩下的数字最小。</p>

<p><strong>注意:</strong></p>

<ul>
	<li><em>num</em> 的长度小于 10002 且&nbsp;≥ <em>k。</em></li>
	<li><em>num</em> 不会包含任何前导零。</li>
</ul>

<p><strong>示例 1 :</strong></p>

<pre>输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
</pre>

<p><strong>示例 2 :</strong></p>

<pre>输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
</pre>

<p>示例<strong> 3 :</strong></p>

<pre>输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/remove-k-digits/solution/remove-k-digits-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        while (k-- > 0) {
            for (int i = 0; i < num.size(); i++) {
                if (i != num.size() - 1 && num[i] <= num[i + 1]) continue;
                num.erase(num.begin() + i);
                break;
            }
        }
        while (num.size() > 1 && num.front() == '0') {
            num.erase(num.begin());
        }
        return num;
    }
};
```




