# `（中等）` [5968.number-of-laser-beams-in-a-bank 银行中的激光束数量](https://leetcode-cn.com/problems/number-of-laser-beams-in-a-bank/)

[contest](https://leetcode-cn.com/contest/weekly-contest-274/problems/number-of-laser-beams-in-a-bank/)

### 题目描述
<div class="notranslate"><p>银行内部的防盗安全装置已经激活。给你一个下标从 <strong>0</strong> 开始的二进制字符串数组 <code>bank</code> ，表示银行的平面图，这是一个大小为 <code>m x n</code> 的二维矩阵。 <code>bank[i]</code> 表示第 <code>i</code> 行的设备分布，由若干 <code>'0'</code> 和若干 <code>'1'</code> 组成。<code>'0'</code> 表示单元格是空的，而 <code>'1'</code> 表示单元格有一个安全设备。</p>

<p>对任意两个安全设备而言，<strong>如果</strong><strong>同时</strong> 满足下面两个条件，则二者之间存在 <strong>一个</strong> 激光束：</p>

<ul>
	<li>两个设备位于两个 <strong>不同行</strong> ：<code>r<sub>1</sub></code> 和 <code>r<sub>2</sub></code> ，其中 <code>r<sub>1</sub> &lt; r<sub>2</sub></code> 。</li>
	<li>满足&nbsp;<code>r<sub>1</sub> &lt; i &lt; r<sub>2</sub></code>&nbsp;的 <strong>所有&nbsp;</strong>行&nbsp;<code>i</code>&nbsp;，都&nbsp;<strong>没有安全设备</strong> 。</li>
</ul>

<p>激光束是独立的，也就是说，一个激光束既不会干扰另一个激光束，也不会与另一个激光束合并成一束。</p>

<p>返回银行中激光束的总数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img style="width: 400px; height: 368px;" src="https://assets.leetcode.com/uploads/2021/12/24/laser1.jpg" alt=""></p>

<pre><strong>输入：</strong>bank = ["011001","000000","010100","001000"]
<strong>输出：</strong>8
<strong>解释：</strong>在下面每组设备对之间，存在一条激光束。总共是 8 条激光束：
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
注意，第 0 行和第 3 行上的设备之间不存在激光束。
这是因为第 2 行存在安全设备，这不满足第 2 个条件。
</pre>

<p><strong>示例 2：</strong></p>

<p><img style="width: 244px; height: 325px;" src="https://assets.leetcode.com/uploads/2021/12/24/laser2.jpg" alt=""></p>

<pre><strong>输入：</strong>bank = ["000","111","000"]
<strong>输出：</strong>0
<strong>解释：</strong>不存在两个位于不同行的设备
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == bank.length</code></li>
	<li><code>n == bank[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>bank[i][j]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
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
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < bank.size(); i++) {
            int cur = calc(bank[i]);
            if (cur == 0) continue;

            ans += cur * pre;
            pre = (cur != 0) ? cur : pre;
        }
        return ans;
    }

    int calc(string& s) {
        int cnt = 0;
        for (auto c : s) {
            cnt += c - '0';
        }
        return cnt;
    }
};
```




