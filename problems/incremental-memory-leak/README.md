# `（中等）` [1860.incremental-memory-leak 增长的内存泄露](https://leetcode-cn.com/problems/incremental-memory-leak/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-52/problems/incremental-memory-leak/)

### 题目描述
<p>给你两个整数&nbsp;<code>memory1</code> 和&nbsp;<code>memory2</code>&nbsp;分别表示两个内存条剩余可用内存的位数。现在有一个程序每秒递增的速度消耗着内存。</p>

<p>在第&nbsp;<code>i</code>&nbsp;秒（秒数从 1 开始），有 <code>i</code>&nbsp;位内存被分配到&nbsp;<strong>剩余内存较多</strong>&nbsp;的内存条（如果两者一样多，则分配到第一个内存条）。如果两者剩余内存都不足 <code>i</code>&nbsp;位，那么程序将 <b>意外退出</b>&nbsp;。</p>

<p>请你返回一个数组，包含<em> </em><code>[crashTime, memory1<sub>crash</sub>, memory2<sub>crash</sub>]</code>&nbsp;，其中&nbsp;<code>crashTime</code>是程序意外退出的时间（单位为秒），<em>&nbsp;</em><code>memory1<sub>crash</sub></code><em> </em>和<em>&nbsp;</em><code>memory2<sub>crash</sub></code><em>&nbsp;</em>分别是两个内存条最后剩余内存的位数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>memory1 = 2, memory2 = 2
<b>输出：</b>[3,1,0]
<b>解释：</b>内存分配如下：
- 第 1 秒，内存条 1 被占用 1 位内存。内存条 1 现在有 1 位剩余可用内存。
- 第 2 秒，内存条 2 被占用 2 位内存。内存条 2 现在有 0 位剩余可用内存。
- 第 3 秒，程序意外退出，两个内存条分别有 1 位和 0 位剩余可用内存。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>memory1 = 8, memory2 = 11
<b>输出：</b>[6,0,4]
<b>解释：</b>内存分配如下：
- 第 1 秒，内存条 2 被占用 1 位内存，内存条 2 现在有 10 位剩余可用内存。
- 第 2 秒，内存条 2 被占用 2 位内存，内存条 2 现在有 8 位剩余可用内存。
- 第 3 秒，内存条 1 被占用 3 位内存，内存条 1 现在有 5 位剩余可用内存。
- 第 4 秒，内存条 2 被占用 4 位内存，内存条 2 现在有 4 位剩余可用内存。
- 第 5 秒，内存条 1 被占用 5 位内存，内存条 1 现在有 0 位剩余可用内存。
- 第 6 秒，程序意外退出，两个内存条分别有 0 位和 4 位剩余可用内存。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= memory1, memory2 &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        long long sec = 1;
        while (sec <= memory1 || sec <= memory2) {
            int& m = (memory1 >= memory2) ? memory1 : memory2;
            m -= sec;
            sec++;
        }
        return { (int)sec, memory1, memory2 };
    }
};
```




