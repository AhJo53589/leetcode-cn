# `（中等）` [423.reconstruct-original-digits-from-english 从英文中重建数字](https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/)

### 题目描述
<p>给你一个字符串 <code>s</code> ，其中包含字母顺序打乱的用英文单词表示的若干数字（<code>0-9</code>）。按 <strong>升序</strong> 返回原始的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "owoztneoer"
<strong>输出：</strong>"012"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "fviefuro"
<strong>输出：</strong>"45"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"]</code> 这些字符之一</li>
	<li><code>s</code> 保证是一个符合题目要求的字符串</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string originalDigits(string s) {
        vector<int> nums(10, 0);

        vector<string> strNums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<vector<int>> chNums(10, vector<int>(26, 0));
        for (int i = 0; i < strNums.size(); i++) {
            for (auto& c : strNums[i]) {
                chNums[i][c - 'a']++;
            }
        }

        vector<int> chOrg(26, 0);
        for (auto& c : s) {
            chOrg[c - 'a']++;
        }

        vector<vector<int>> steps = {{0, 2, 4, 6, 8}, {1, 3, 5, 7}, {9}};
        vector<char> key = {'z', 'o', 'w', 't', 'u', 'f', 'x', 's', 'g', 'n'};
        for (auto& st : steps) {
            for (auto& t : st) {
                while (chOrg[key[t] - 'a'] > 0) {
                    nums[t]++;
                    sub(chOrg, chNums[t]);
                }
            }
        }

        string ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.insert(ans.end(), nums[i], '0' + i);
        }
        return ans;
    }

    void sub(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            a[i] -= b[i];
        }
    }
};
```




