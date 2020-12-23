# `（中等）` [1654.minimum-jumps-to-reach-home 到家的最少跳跃次数](https://leetcode-cn.com/problems/minimum-jumps-to-reach-home/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-39/problems/minimum-jumps-to-reach-home/)

### 题目描述
<p>有一只跳蚤的家在数轴上的位置&nbsp;<code>x</code>&nbsp;处。请你帮助它从位置&nbsp;<code>0</code>&nbsp;出发，到达它的家。</p>

<p>跳蚤跳跃的规则如下：</p>

<ul>
	<li>它可以 <strong>往前</strong> 跳恰好 <code>a</code>&nbsp;个位置（即往右跳）。</li>
	<li>它可以 <strong>往后</strong>&nbsp;跳恰好 <code>b</code>&nbsp;个位置（即往左跳）。</li>
	<li>它不能 <strong>连续</strong> 往后跳 <code>2</code> 次。</li>
	<li>它不能跳到任何&nbsp;<code>forbidden</code>&nbsp;数组中的位置。</li>
</ul>

<p>跳蚤可以往前跳 <strong>超过</strong>&nbsp;它的家的位置，但是它 <strong>不能跳到负整数</strong>&nbsp;的位置。</p>

<p>给你一个整数数组&nbsp;<code>forbidden</code>&nbsp;，其中&nbsp;<code>forbidden[i]</code>&nbsp;是跳蚤不能跳到的位置，同时给你整数&nbsp;<code>a</code>，&nbsp;<code>b</code>&nbsp;和&nbsp;<code>x</code>&nbsp;，请你返回跳蚤到家的最少跳跃次数。如果没有恰好到达 <code>x</code>&nbsp;的可行方案，请你返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
<b>输出：</b>3
<b>解释：</b>往前跳 3 次（0 -&gt; 3 -&gt; 6 -&gt; 9），跳蚤就到家了。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
<b>输出：</b>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
<b>输出：</b>2
<b>解释：</b>往前跳一次（0 -&gt; 16），然后往回跳一次（16 -&gt; 7），跳蚤就到家了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= forbidden.length &lt;= 1000</code></li>
	<li><code>1 &lt;= a, b, forbidden[i] &lt;= 2000</code></li>
	<li><code>0 &lt;= x &lt;= 2000</code></li>
	<li><code>forbidden</code>&nbsp;中所有位置互不相同。</li>
	<li>位置&nbsp;<code>x</code>&nbsp;不在 <code>forbidden</code>&nbsp;中。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if (x == 0) return 0;
        unordered_set<int> vi(forbidden.begin(), forbidden.end());
        vi.insert(0);

        queue<pair<int, bool>> que;
        que.push({ 0, false });

        int cnt = 0;
        while (!que.empty()) {
            cnt++;
            for (int len = que.size(); len > 0; len--) {
                auto [pos, jump] = que.front();
                que.pop();

                if (pos > 100000) continue;
                //if (pos > x + a * b) continue;

                if (pos + a == x) return cnt;
                if (vi.find(pos + a) == vi.end()) {
                    vi.insert(pos + a);
                    que.push({ pos + a, false });
                }

                if (jump) continue;
                if (pos - b == x) return cnt;
                if (pos - b >= 0 && vi.find(pos - b) == vi.end()) {
                    que.push({ pos - b, true });
                }
            }
        }

        return -1;
    }
};
```




