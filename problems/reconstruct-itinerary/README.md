# `（中等）` [332.reconstruct-itinerary 重新安排行程](https://leetcode-cn.com/problems/reconstruct-itinerary/)

### 题目描述
<p>给定一个机票的字符串二维数组 <code>[from, to]</code>，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>如果存在多种有效的行程，请你按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前</li>
	<li>所有的机场都用三个大写字母表示（机场代码）。</li>
	<li>假定所有机票至少存在一种合理的行程。</li>
	<li>所有的机票必须都用一次 且 只能用一次。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><code><strong>输入：</strong></code><code>[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]</code>
<strong>输出：</strong><code>["JFK", "MUC", "LHR", "SFO", "SJC"]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><code><strong>输入：</strong></code><code>[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]</code>
<strong>输出：</strong><code>["JFK","ATL","JFK","SFO","ATL","SFO"]</code>
<strong>解释：</strong>另一种有效的行程是&nbsp;<code>["JFK","SFO","ATL","JFK","ATL","SFO"]</code>。但是它自然排序更大更靠后。</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) {
            tk[t[0]].push_back(t[1]);
            vi[t[0]].push_back(false);
        }
        for (auto& t : tk) {
            sort(t.second.begin(), t.second.end());
        }
        ans.push_back("JFK");
        dfs(tickets.size() + 1);
        return ans;
    }

    bool dfs(int len) {
        if (ans.size() == len) return true;
        for (int i = 0; i < tk[ans.back()].size(); i++) {
            if (vi[ans.back()][i]) continue;
            vi[ans.back()][i] = true;
            ans.push_back(tk[ans.back()][i]);
            if (dfs(len)) return true;
            ans.pop_back();
            vi[ans.back()][i] = false;
        }
        return false;
    }

private:
    unordered_map<string, vector<string>> tk;
    unordered_map<string, vector<bool>> vi;
    vector<string> ans;
};
```




