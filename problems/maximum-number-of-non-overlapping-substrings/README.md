# `（中等）` [5466.maximum-number-of-non-overlapping-substrings 最多的不重叠子字符串](https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-substrings/)

[contest](https://leetcode-cn.com/contest/weekly-contest-198/problems/maximum-number-of-non-overlapping-substrings/)

### 题目描述
<p>给你一个只包含小写字母的字符串&nbsp;<code>s</code>&nbsp;，你需要找到 <code>s</code>&nbsp;中最多数目的非空子字符串，满足如下条件：</p>

<ol>
	<li>这些字符串之间互不重叠，也就是说对于任意两个子字符串&nbsp;<code>s[i..j]</code> 和&nbsp;<code>s[k..l]</code>&nbsp;，要么&nbsp;<code>j < k</code>&nbsp;要么&nbsp;<code>i > l</code>&nbsp;。</li>
	<li>如果一个子字符串包含字符&nbsp;<code>c</code>&nbsp;，那么&nbsp;<code>s</code>&nbsp;中所有&nbsp;<code>c</code>&nbsp;字符都应该在这个子字符串中。</li>
</ol>

<p>请你找到满足上述条件的最多子字符串数目。如果有多个解法有相同的子字符串数目，请返回这些子字符串总长度最小的一个解。可以证明最小总长度解是唯一的。</p>

<p>请注意，你可以以 <strong>任意</strong>&nbsp;顺序返回最优解的子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "adefaddaccc"
<strong>输出：</strong>["e","f","ccc"]
<strong>解释：</strong>下面为所有满足第二个条件的子字符串：
[
&nbsp; "adefaddaccc"
&nbsp; "adefadda",
&nbsp; "ef",
&nbsp; "e",
  "f",
&nbsp; "ccc",
]
如果我们选择第一个字符串，那么我们无法再选择其他任何字符串，所以答案为 1 。如果我们选择 "adefadda" ，剩下子字符串中我们只可以选择 "ccc" ，它是唯一不重叠的子字符串，所以答案为 2 。同时我们可以发现，选择 "ef" 不是最优的，因为它可以被拆分成 2 个子字符串。所以最优解是选择 ["e","f","ccc"] ，答案为 3 。不存在别的相同数目子字符串解。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abbaccd"
<strong>输出：</strong>["d","bb","cc"]
<strong>解释：</strong>注意到解 ["d","abba","cc"] 答案也为 3 ，但它不是最优解，因为它的总长度更长。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10^5</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-substrings/solution/non-overlapping-substrings-by-ikaruga/)

### 答题
``` C++
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> subs(26);
        for (int i = 0; i < subs.size(); i++) {
            subs[i].push_back(INT_MAX);
            char c = 'a' + i;
            if (s.find(c) == string::npos) continue;
            subs[i].push_back(s.find_first_of(c));
            subs[i].push_back(s.find_last_of(c));
            subs[i][0] = subs[i][2] - subs[i][1] + 1;
        }

        for (int i = 0; i < subs.size(); i++) {
            if (subs[i].size() == 1) continue;
            subs[i] = getFullSub(subs, s, subs[i][1], subs[i][2]);
        }

        sort(subs.begin(), subs.end());

        vector<string> ans;
        vector<bool> vi(s.size(), false);
        for (auto sub : subs) {
            if (sub.size() == 1) break;

            bool check = true;
            for (int j = sub[1]; j <= sub[2] && check; j++) {
                check = !vi[j];
            }
            if (!check) continue;

            for (int j = sub[1]; j <= sub[2]; j++) {
                vi[j] = true;
            }
            ans.push_back(s.substr(sub[1], sub[0]));
        }
        return ans;
    }

    vector<int> getFullSub(vector<vector<int>>& subs, string& s, int left, int right) {
        for (int j = left + 1; j < right; j++) {
            int n = s[j] - 'a';
            if (left <= subs[n][1] && right >= subs[n][2]) continue;
            left = min(left, subs[n][1]);
            right = max(right, subs[n][2]);
            j = left;
        }
        return { right - left + 1, left, right };
    }
};
```




