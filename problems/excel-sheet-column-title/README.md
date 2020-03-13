# `（简单）` [168.excel-sheet-column-title Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)

### 题目描述
<p>给定一个正整数，返回它在 Excel 表中相对应的列名称。</p>

<p>例如，</p>

<pre>    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
</pre>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 1
<strong>输出:</strong> "A"
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> 28
<strong>输出:</strong> "AB"
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre><strong>输入:</strong> 701
<strong>输出:</strong> "ZY"
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/excel-sheet-column-title/solution/168-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    string convertToTitle(int n) 
    {
        string ans = "";
        while (n > 0)
        {
            n -= 1;
            ans.push_back('A' + (n % 26));
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```




