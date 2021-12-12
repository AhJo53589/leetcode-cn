# `（中等）` [911.online-election 在线选举](https://leetcode-cn.com/problems/online-election/)

### 题目描述
<div class="notranslate"><p>给你两个整数数组 <code>persons</code> 和 <code>times</code> 。在选举中，第&nbsp;<code>i</code>&nbsp;张票是在时刻为&nbsp;<code>times[i]</code>&nbsp;时投给候选人 <code>persons[i]</code>&nbsp;的。</p>

<p>对于发生在时刻 <code>t</code> 的每个查询，需要找出在&nbsp;<code>t</code> 时刻在选举中领先的候选人的编号。</p>

<p>在&nbsp;<code>t</code> 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。</p>

<p>实现 <code>TopVotedCandidate</code> 类：</p>

<ul>
	<li><code>TopVotedCandidate(int[] persons, int[] times)</code> 使用&nbsp;<code>persons</code> 和 <code>times</code> 数组初始化对象。</li>
	<li><code>int q(int t)</code> 根据前面描述的规则，返回在时刻 <code>t</code> 在选举中领先的候选人的编号。</li>
</ul>
&nbsp;

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>
["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
<strong>输出：</strong>
[null, 0, 1, 1, 0, 0, 1]

<strong>解释：</strong>
TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
topVotedCandidate.q(3); // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
topVotedCandidate.q(12); // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
topVotedCandidate.q(25); // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
topVotedCandidate.q(15); // 返回 0
topVotedCandidate.q(24); // 返回 0
topVotedCandidate.q(8); // 返回 1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= persons.length &lt;= 5000</code></li>
	<li><code>times.length == persons.length</code></li>
	<li><code>0 &lt;= persons[i] &lt; persons.length</code></li>
	<li><code>0 &lt;= times[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>times</code> 是一个严格递增的有序数组</li>
	<li><code>times[0] &lt;= t &lt;= 10<sup>9</sup></code></li>
	<li>每个测试用例最多调用 <code>10<sup>4</sup></code> 次 <code>q</code></li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        vector<int> vote(persons.size(), 0);
		int top = 0;
        for (int i = 0; i < times.size(); i++) {
            vote[persons[i]]++;
			top = (vote[persons[i]] >= vote[top]) ? persons[i] : top;
            mp[times[i]] = top;
        }
    }
    
    int q(int t) {
        auto it = mp.upper_bound(t);
		it--;
        return it->second;
    }

private:
    map<int, int> mp;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

```




