# `（中等）` [451.sort-characters-by-frequency 根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency/)

### 题目描述
<p>给定一个字符串，请将字符串里的字符按照出现的频率降序排列。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong>
"tree"

<strong>输出:</strong>
"eert"

<strong>解释:
</strong>'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong>
"cccaaa"

<strong>输出:</strong>
"cccaaa"

<strong>解释:
</strong>'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong>
"Aabb"

<strong>输出:</strong>
"bbAa"

<strong>解释:
</strong>此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
</pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/sort-characters-by-frequency/solution/sort-characters-by-frequency-by-ikaruga-317u/)

### 答题
``` C++
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (auto c : s) {
            cnt[c]++;
        }

        multimap<int, char> mm;
        for (auto [c, n] : cnt) {
            mm.insert({n, c});
        }

        string ans;
        for (auto [n, c] : mm) {
            for (int i = 0; i < n; i++) {
                ans += c;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```




