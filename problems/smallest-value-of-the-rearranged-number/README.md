# `（中等）` [6001.smallest-value-of-the-rearranged-number 重排数字的最小值](https://leetcode-cn.com/problems/smallest-value-of-the-rearranged-number/)

[contest](https://leetcode-cn.com/contest/weekly-contest-279/problems/smallest-value-of-the-rearranged-number/)

### 题目描述
<div class="notranslate"><p>给你一个整数 <code>num</code> 。<strong>重排</strong> <code>num</code> 中的各位数字，使其值 <strong>最小化</strong> 且不含 <strong>任何</strong> 前导零。</p>

<p>返回不含前导零且值最小的重排数字。</p>

<p>注意，重排各位数字后，<code>num</code> 的符号不会改变。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 310
<strong>输出：</strong>103
<strong>解释：</strong>310 中各位数字的可行排列有：013、031、103、130、301、310 。
不含任何前导零且值最小的重排数字是 103 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = -7605
<strong>输出：</strong>-7650
<strong>解释：</strong>-7605 中各位数字的部分可行排列为：-7650、-6705、-5076、-0567。
不含任何前导零且值最小的重排数字是 -7650 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-10<sup>15</sup> &lt;= num &lt;= 10<sup>15</sup></code></li>
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
    long long smallestNumber(long long num) {
        if (num == 0) return 0;

        int flag = num / abs(num);
        num *= flag;
        vector<int> dd(10, 0);
        while (num != 0) {
            dd[num % 10]++;
            num /= 10;
        }

        long long ans = 0;
        if (flag < 0) {
            for (int i = 9; i >= 0; i--) {
                addNum(ans, i, dd[i]);
            }
        }
        else {
            int first = getFirstNotZero(dd);
            ans += first;
            for (int i = 0; i < 10; i++) {
                addNum(ans, i, dd[i]);
            }
        }
        return 1LL * flag * ans;
    }

    void addNum(long long &ans, int n, int c) {
        for (int j = 0; j < c; j++) {
            ans *= 10;
            ans += n;
        }
    }

    int getFirstNotZero(vector<int>& dd) {
        for (int i = 1; i < 10; i++) {
            if (dd[i] == 0) continue;
            dd[i]--;
            return i;
        }
        return 0;
    }
};
```




