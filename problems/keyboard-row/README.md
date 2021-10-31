# `（简单）` [500.keyboard-row 键盘行](https://leetcode-cn.com/problems/keyboard-row/)

### 题目描述
<div class="notranslate"><p>给你一个字符串数组 <code>words</code> ，只返回可以使用在 <strong>美式键盘</strong> 同一行的字母打印出来的单词。键盘如下图所示。</p>

<p><strong>美式键盘</strong> 中：</p>

<ul>
	<li>第一行由字符 <code>"qwertyuiop"</code> 组成。</li>
	<li>第二行由字符 <code>"asdfghjkl"</code> 组成。</li>
	<li>第三行由字符 <code>"zxcvbnm"</code> 组成。</li>
</ul>

<p><img style="width: 100%; max-width: 600px" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/keyboard.png" alt="American keyboard"></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["Hello","Alaska","Dad","Peace"]
<strong>输出：</strong>["Alaska","Dad"]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["omk"]
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = ["adsdf","sfd"]
<strong>输出：</strong>["adsdf","sfd"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 20</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 由英文字母（小写和大写字母）组成</li>
</ul>
</div>

---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> keyboard(3);
        keyboard[0] = unordered_set<char> {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        keyboard[1] = unordered_set<char> {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        keyboard[2] = unordered_set<char> {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        vector<string> ans;
        for (auto& w : words) {
            int line = -1;
            for (auto c : w) {
                auto C = toupper(c);
                c = tolower(c);
                int cur = -1;
                for (int i = 0; i < keyboard.size(); i++) {
                    if (keyboard[i].find(c) != keyboard[i].end() ||
                    keyboard[i].find(C) != keyboard[i].end()) {
                        cur = i;
                        break;
                    }
                }
                if (line != -1 && line != cur) {
                    line = -2;
                    break;
                }
                line = cur;
            }
            if (line >= 0) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
```




