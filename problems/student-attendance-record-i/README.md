# `（简单）` [551.student-attendance-record-i 学生出勤记录 I](https://leetcode-cn.com/problems/student-attendance-record-i/)

### 题目描述
<p>给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：</p>

<ol>
	<li><strong>'A'</strong> : Absent，缺勤</li>
	<li><strong>'L'</strong> : Late，迟到</li>
	<li><strong>'P'</strong> : Present，到场</li>
</ol>

<p>如果一个学生的出勤记录中不<strong>超过一个'A'(缺勤)</strong>并且<strong>不超过两个连续的'L'(迟到)</strong>,那么这个学生会被奖赏。</p>

<p>你需要根据这个学生的出勤记录判断他是否会被奖赏。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> "PPALLP"
<strong>输出:</strong> True
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> "PPALLL"
<strong>输出:</strong> False
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/student-attendance-record-i/solution/student-attendance-record-i-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    bool checkRecord(string s) 
    {
        int cnt_A = 0;
        int cnt_L = 0;
        for (auto c : s)
        {
            cnt_A += (c == 'A');
            cnt_L = (c != 'L') ? 0 : cnt_L;
            cnt_L += (c == 'L');
            if (cnt_A > 1 || cnt_L > 2) return false;
        }
        return true;
    }
};
```




