# `（中等）` [1996.the-number-of-weak-characters-in-the-game 游戏中弱角色的数量](https://leetcode-cn.com/problems/the-number-of-weak-characters-in-the-game/)

### 题目描述
<p>你正在参加一个多角色游戏，每个角色都有两个主要属性：<strong>攻击</strong> 和 <strong>防御</strong> 。给你一个二维整数数组 <code>properties</code> ，其中 <code>properties[i] = [attack<sub>i</sub>, defense<sub>i</sub>]</code> 表示游戏中第 <code>i</code> 个角色的属性。</p>

<p>如果存在一个其他角色的攻击和防御等级 <strong>都严格高于</strong> 该角色的攻击和防御等级，则认为该角色为 <strong>弱角色</strong> 。更正式地，如果认为角色 <code>i</code> <strong>弱于</strong> 存在的另一个角色 <code>j</code> ，那么 <code>attack<sub>j</sub> &gt; attack<sub>i</sub></code> 且 <code>defense<sub>j</sub> &gt; defense<sub>i</sub></code> 。</p>

<p>返回 <strong>弱角色</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>properties = [[5,5],[6,3],[3,6]]
<strong>输出：</strong>0
<strong>解释：</strong>不存在攻击和防御都严格高于其他角色的角色。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>properties = [[2,2],[3,3]]
<strong>输出：</strong>1
<strong>解释：</strong>第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>properties = [[1,5],[10,4],[4,3]]
<strong>输出：</strong>1
<strong>解释：</strong>第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= properties.length &lt;= 10<sup>5</sup></code></li>
	<li><code>properties[i].length == 2</code></li>
	<li><code>1 &lt;= attack<sub>i</sub>, defense<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<int> st;
        sort(properties.begin(), properties.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for (int i = 0; i < properties.size(); i++) {
            while (!st.empty() && properties[st.back()][1] < properties[i][1]) {
                st.pop_back();
            }
            st.push_back(i);
        }
        return properties.size() - st.size();
    }
};
```




