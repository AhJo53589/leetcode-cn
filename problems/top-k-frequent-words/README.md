# `（中等）` [692.top-k-frequent-words 前K个高频单词](https://leetcode-cn.com/problems/top-k-frequent-words/)

### 题目描述
<p>给一非空的单词列表，返回前&nbsp;<em>k&nbsp;</em>个出现次数最多的单词。</p>

<p>返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入:</strong> ["i", "love", "leetcode", "i", "love", "coding"], k = 2
<strong>输出:</strong> ["i", "love"]
<strong>解析:</strong> "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<pre><strong>输入:</strong> ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
<strong>输出:</strong> ["the", "is", "sunny", "day"]
<strong>解析:</strong> "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
</pre>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ol>
	<li>假定 <em>k</em> 总为有效值， 1 ≤ <em>k</em> ≤ 集合元素数。</li>
	<li>输入的单词均由小写字母组成。</li>
</ol>

<p>&nbsp;</p>

<p><strong>扩展练习：</strong></p>

<ol>
	<li>尝试以&nbsp;<em>O</em>(<em>n</em> log <em>k</em>) 时间复杂度和&nbsp;<em>O</em>(<em>n</em>) 空间复杂度解决。</li>
</ol>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& w : words) {
            cnt[w]++;
        }

        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        auto pq = priority_queue { cmp, vector<pair<string, int>> {} };
        for (auto& it : cnt) {
            pq.emplace(it);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
```




