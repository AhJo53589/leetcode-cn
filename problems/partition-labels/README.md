# `（中等）` [763.partition-labels 划分字母区间](https://leetcode-cn.com/problems/partition-labels/)

### 题目描述
<p>字符串 <code>S</code> 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>S = "ababcbacadefegdehijhklij"
<strong>输出：</strong>[9,7,8]
<strong>解释：</strong>
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>S</code>的长度在<code>[1, 500]</code>之间。</li>
	<li><code>S</code>只包含小写字母 <code>'a'</code> 到 <code>'z'</code> 。</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> pos(26, 0);
        for (int i = 0; i < S.size(); i++) {
            pos[S[i] - 'a'] = i;
        }

        vector<int> ans;
        int k = 0;
        int cut = -1;
        for (int i = 0; i < S.size(); i++) {
            k = max(k, pos[S[i] - 'a']);
            if (i == k) {
                ans.push_back(i - cut);
                cut = i;
            }
        }
        return ans;
    }
};
```




