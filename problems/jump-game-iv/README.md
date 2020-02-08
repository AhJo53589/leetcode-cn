# `（困难）` [5314.jump-game-iv 跳跃游戏 IV](https://leetcode-cn.com/problems/jump-game-iv/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-19/problems/jump-game-iv/)

### 题目描述
<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;，你一开始在数组的第一个元素处。</p>

<p>每一步，你可以从下标&nbsp;<code>i</code>&nbsp;跳到下标：</p>

<ul>
	<li><code>i + 1</code>&nbsp;满足：<code>i + 1 &lt; arr.length</code></li>
	<li><code>i - 1</code>&nbsp;满足：<code>i - 1 &gt;= 0</code></li>
	<li><code>j</code>&nbsp;满足：<code>arr[i] == arr[j]</code>&nbsp;且&nbsp;<code>i != j</code></li>
</ul>

<p>请你返回到达数组最后一个元素的下标处所需的&nbsp;<strong>最少操作次数</strong>&nbsp;。</p>

<p>注意：任何时候你都不能跳到数组外面。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [100,-23,-23,404,100,23,23,23,3,404]
<strong>输出：</strong>3
<strong>解释：</strong>那你需要跳跃 3 次，下标依次为 0 --&gt; 4 --&gt; 3 --&gt; 9 。下标 9 为数组的最后一个元素的下标。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [7]
<strong>输出：</strong>0
<strong>解释：</strong>一开始就在最后一个元素处，所以你不需要跳跃。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [7,6,9,6,9,6,9,7]
<strong>输出：</strong>1
<strong>解释：</strong>你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [6,1,9]
<strong>输出：</strong>2
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [11,22,7,7,7,7,7,7,7,22,13]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10^4</code></li>
	<li><code>-10^8 &lt;= arr[i] &lt;= 10^8</code></li>
</ul>



---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/jump-game-iv/solution/5314-by-ikaruga/)

### 答题
``` C++
int minJumps(vector<int>& arr) 
{
    unordered_map<int, vector<int>> same;
    int pre_i = 0;
    int pre_val = arr[0];
    same[pre_val].push_back(pre_i);
    for (size_t i = 1; i < arr.size(); i++)
    {
        int val = arr[i];
        if (val == pre_val && i != arr.size() - 1)
        {
            pre_i = i;
            continue;
        }
        same[pre_val].push_back(pre_i);
        pre_i = i;
        pre_val = val;
        same[pre_val].push_back(pre_i);
    }

    vector<int> vi(arr.size(), 0);
    queue<int> que;
    que.push(0);
    vi[0] = 1;

    while (!que.empty())
    {
        auto q = que.front();
        que.pop();
        if (q == arr.size() - 1) break;

        if (q != 0 && vi[q - 1] == 0)
        {
            que.push(q - 1);
            vi[q - 1] = vi[q] + 1;
        }
        if (q != arr.size() - 1 && vi[q + 1] == 0)
        {
            que.push(q + 1);
            vi[q + 1] = vi[q] + 1;
        }
        auto s = same[arr[q]];
        for (size_t i = s.size() - 1; i < s.size(); i--)
        {
            if (vi[s[i]] != 0) continue;
            que.push(s[i]);
            vi[s[i]] = vi[q] + 1;
        }
    }

    return vi[arr.size() - 1] - 1;
}
```




