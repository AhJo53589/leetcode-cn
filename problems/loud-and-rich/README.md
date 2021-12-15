# `（中等）` [851.loud-and-rich 喧闹和富有](https://leetcode-cn.com/problems/loud-and-rich/)

### 题目描述
<p>有一组 <code>n</code> 个人作为实验对象，从 <code>0</code> 到 <code>n - 1</code> 编号，其中每个人都有不同数目的钱，以及不同程度的安静值（quietness）。为了方便起见，我们将编号为&nbsp;<code>x</code>&nbsp;的人简称为 "person&nbsp;<code>x</code>&nbsp;"。</p>

<p>给你一个数组 <code>richer</code> ，其中 <code>richer[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示 person&nbsp;<code>a<sub>i</sub></code>&nbsp;比 person&nbsp;<code>b<sub>i</sub></code>&nbsp;更有钱。另给你一个整数数组 <code>quiet</code> ，其中&nbsp;<code>quiet[i]</code> 是 person <code>i</code> 的安静值。<code>richer</code> 中所给出的数据 <strong>逻辑自恰</strong>（也就是说，在 person <code>x</code> 比 person <code>y</code> 更有钱的同时，不会出现 person <code>y</code> 比 person <code>x</code> 更有钱的情况 ）。</p>

<p>现在，返回一个整数数组 <code>answer</code> 作为答案，其中&nbsp;<code>answer[x] = y</code>&nbsp;的前提是，在所有拥有的钱肯定不少于&nbsp;person&nbsp;<code>x</code>&nbsp;的人中，person&nbsp;<code>y</code>&nbsp;是最安静的人（也就是安静值&nbsp;<code>quiet[y]</code>&nbsp;最小的人）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
<strong>输出：</strong>[5,5,2,5,4,5,6,7]
<strong>解释： </strong>
answer[0] = 5，
person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0 有更多的钱。
唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
但是目前还不清楚他是否比 person 0 更有钱。
answer[7] = 7，
在所有拥有的钱肯定不少于 person 7 的人中（这可能包括 person 3，4，5，6 以及 7），
最安静（有较低安静值 quiet[x]）的人是 person 7。
其他的答案也可以用类似的推理来解释。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>richer = [], quiet = [0]
<strong>输出：</strong>[0]
</pre>
&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == quiet.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>0 &lt;= quiet[i] &lt; n</code></li>
	<li><code>quiet</code> 的所有值 <strong>互不相同</strong></li>
	<li><code>0 &lt;= richer.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i </sub>!= b<sub>i</sub></code></li>
	<li><code>richer</code> 中的所有数对 <strong>互不相同</strong></li>
	<li>对<strong> </strong><code>richer</code> 的观察在逻辑上是一致的</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for (auto& r : richer) {
            um[r[1]].push_back(r[0]);
        }

        vector<int> ans(quiet.size(), 0);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = check(i, quiet);
        }
        return ans;
    }

    int check(int n, vector<int>& quiet) {
        if (cache.find(n) != cache.end()) return cache[n];

        int x = n;
        for (auto& r : um[n]) {
            x = (quiet[x] > quiet[r]) ? r : x;
            int y = check(r, quiet);
            x = (quiet[x] > quiet[y]) ? y : x;
        }
        cache[n] = x;
        return x;
    }

private:
    unordered_map<int, vector<int>> um;
    unordered_map<int, bool> vi;
    unordered_map<int, int> cache;
};
```




