# `（中等）` [1404.number-of-steps-to-reduce-a-number-in-binary-representation-to-one 将二进制表示减到 1 的步骤数](https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)

[contest](https://leetcode-cn.com/contest/weekly-contest-183/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)

### 题目描述
<p>给你一个以二进制形式表示的数字 <code>s</code> 。请你返回按下述规则将其减少到 1 所需要的步骤数：</p>

<ul>
	<li>
	<p>如果当前数字为偶数，则将其除以 2 。</p>
	</li>
	<li>
	<p>如果当前数字为奇数，则将其加上 1 。</p>
	</li>
</ul>

<p>题目保证你总是可以按上述规则将测试用例变为 1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "1101"
<strong>输出：</strong>6
<strong>解释：</strong>"1101" 表示十进制数 13 。
Step 1) 13 是奇数，加 1 得到 14&nbsp;
Step 2) 14 是偶数，除 2 得到 7
Step 3) 7  是奇数，加 1 得到 8
Step 4) 8  是偶数，除 2 得到 4&nbsp; 
Step 5) 4  是偶数，除 2 得到 2&nbsp;
Step 6) 2  是偶数，除 2 得到 1&nbsp; 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "10"
<strong>输出：</strong>1
<strong>解释：</strong>"10" 表示十进制数 2 。
Step 1) 2 是偶数，除 2 得到 1 
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "1"
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length&nbsp;&lt;= 500</code></li>
	<li><code>s</code> 由字符 <code>'0'</code> 或 <code>'1'</code> 组成。</li>
	<li><code>s[0] == '1'</code></li>
</ul>

            

---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/solution/number-of-steps-by-ikaruga/)

### 答题
``` C++
    int numSteps(string s) 
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') continue;
            s = s.substr(i, s.size() - i);
            break;
        }
        while (s.back() == '0')
        {
            ans++;
            s.pop_back();
        }
        if (s.size() == 1) return ans;

        s.insert(s.begin(), '0');
        for (int i = s.size() - 1; i > 0;)
        {
            int cnt = 1;
            while (i - cnt >= 0 && s[i - cnt] == '1')
            {
                cnt++;
            }
            ans += cnt + 1;
            i -= cnt;
        }
        return ans;
    }
```




