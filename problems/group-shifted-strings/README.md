# `（中等）` [249.group-shifted-strings 移位字符串分组](https://leetcode-cn.com/problems/group-shifted-strings/)

### 题目描述
<p>给定一个字符串，对该字符串可以进行 “移位” 的操作，也就是将字符串中每个字母都变为其在字母表中后续的字母，比如：<code>"abc" -&gt; "bcd"</code>。这样，我们可以持续进行 “移位” 操作，从而生成如下移位序列：</p>

<pre>"abc" -&gt; "bcd" -&gt; ... -&gt; "xyz"</pre>

<p>给定一个包含仅小写字母字符串的列表，将该列表中所有满足&nbsp;“移位” 操作规律的组合进行分组并返回。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong><code>["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]</code>
<strong>输出：</strong>
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
<strong>解释：</strong>可以认为字母表首尾相接，所以 'z' 的后续为 'a'，所以 ["az","ba"] 也满足 “移位” 操作规律。</pre>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashmap;
        
        for (auto u : strings) {
            string temp = u;
            for (int i = 0; i < u.size(); i++) {
                u[i] = (u[i] - temp[0] + 26) % 26 + 'a';
            }
            hashmap[u].push_back(temp);
        } 

        for (auto u : hashmap) {
            ans.push_back(u.second);
        }

        return ans;
    }
};
```




