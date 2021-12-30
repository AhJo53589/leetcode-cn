# `（中等）` [846.hand-of-straights 一手顺子](https://leetcode-cn.com/problems/hand-of-straights/)

### 题目描述
<p>Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 <code>groupSize</code> ，并且由 <code>groupSize</code> 张连续的牌组成。</p>

<p>给你一个整数数组 <code>hand</code> 其中 <code>hand[i]</code> 是写在第 <code>i</code> 张牌，和一个整数 <code>groupSize</code> 。如果她可能重新排列这些牌，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
<strong>输出：</strong>true
<strong>解释：</strong>Alice 手中的牌可以被重新排列为 <code>[1,2,3]，[2,3,4]，[6,7,8]</code>。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>hand = [1,2,3,4,5], groupSize = 4
<strong>输出：</strong>false
<strong>解释：</strong>Alice 手中的牌无法被重新排列成几个大小为 4 的组。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hand.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= hand[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= groupSize &lt;= hand.length</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>此题目与 1296 重复：<a href="https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/">https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/</a></p>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> cnts;
        for (auto n : hand) cnts[n]++;

        for (auto it = cnts.begin(); it != cnts.end(); it++) {
            while (it->second != 0) {
                int _first = it->first;
                it->second--;
                for (int i = 1; i < groupSize; i++) {
                    int t = _first + i;
                    if (cnts.count(t) == 0) return false;
                    if (cnts[t]-- == 0) return false;
                }
            }
        }
        return true;
    }
};
```




