# `（困难）` [466.count-the-repetitions 统计重复个数](https://leetcode-cn.com/problems/count-the-repetitions/)

### 题目描述
<p>由 n 个连接的字符串 s 组成字符串 S，记作&nbsp;<code>S = [s,n]</code>。例如，<code>["abc",3]</code>=“abcabcabc”。</p>

<p>如果我们可以从 s2<sub>&nbsp;</sub>中删除某些字符使其变为 s1，则称字符串 s1<sub>&nbsp;</sub>可以从字符串 s2 获得。例如，根据定义，"abc" 可以从 “abdbec” 获得，但不能从 “acbbe” 获得。</p>

<p>现在给你两个非空字符串 s1&nbsp;和 s2（每个最多 100 个字符长）和两个整数 0 ≤ n1 ≤ 10<sup>6&nbsp;</sup>和 1 ≤ n2 ≤ 10<sup>6</sup>。现在考虑字符串 S1 和 S2，其中 <code>S1=[s1,n1]</code>&nbsp;、<code>S2=[s2,n2]</code> 。</p>

<p>请你找出一个可以满足使<code>[S2,M]</code> 从 <code>S1</code>&nbsp;获得的最大整数 M 。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>输入：
s1 ="acb",n1 = 4
s2 ="ab",n2 = 2

返回：
2
</pre>


---
### 思路
```
```



### 答题
``` C++
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        vector<int> repeatCnt(102, 0);
        vector<int> nextIdx(102, -1);
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k)
        {
            int tag = 0;
            for (int i = 0; i < s1.size(); ++i) 
            {
                if (s1[i] == s2[j])
                {
                    ++j;
                    tag = 1;
                    if (j == s2.size())
                    {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            if (tag == 0) return 0;
            repeatCnt[k] = cnt;
            if (nextIdx[j] != -1)
            {
                int start = nextIdx[j];
                int interval = k - start;
                int repeat = (n1 - start) / interval;
                int patternCnt = (repeatCnt[k] - repeatCnt[start]) * repeat;
                int remainCnt = repeatCnt[start + (n1 - start) % interval];
                return (patternCnt + remainCnt) / n2;
            }
            else
            {
                nextIdx[j] = k;
            }

        }
        return repeatCnt[n1] / n2;
    }
```




