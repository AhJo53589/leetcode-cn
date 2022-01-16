# `（简单）` [5980.divide-a-string-into-groups-of-size-k 将字符串拆分为若干长度为 k 的组](https://leetcode-cn.com/problems/divide-a-string-into-groups-of-size-k/)

[contest](https://leetcode-cn.com/contest/weekly-contest-276/problems/divide-a-string-into-groups-of-size-k/)

### 题目描述
<div class="notranslate"><p>字符串 <code>s</code> 可以按下述步骤划分为若干长度为 <code>k</code> 的组：</p>

<ul>
	<li>第一组由字符串中的前 <code>k</code> 个字符组成，第二组由接下来的 <code>k</code> 个字符串组成，依此类推。每个字符都能够成为 <strong>某一个</strong> 组的一部分。</li>
	<li>对于最后一组，如果字符串剩下的字符 <strong>不足</strong> <code>k</code> 个，需使用字符 <code>fill</code> 来补全这一组字符。</li>
</ul>

<p>注意，在去除最后一个组的填充字符 <code>fill</code>（如果存在的话）并按顺序连接所有的组后，所得到的字符串应该是 <code>s</code> 。</p>

<p>给你一个字符串 <code>s</code> ，以及每组的长度 <code>k</code> 和一个用于填充的字符 <code>fill</code> ，按上述步骤处理之后，返回一个字符串数组，该数组表示 <code>s</code> 分组后 <strong>每个组的组成情况</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abcdefghi", k = 3, fill = "x"
<strong>输出：</strong>["abc","def","ghi"]
<strong>解释：</strong>
前 3 个字符是 "abc" ，形成第一组。
接下来 3 个字符是 "def" ，形成第二组。
最后 3 个字符是 "ghi" ，形成第三组。
由于所有组都可以由字符串中的字符完全填充，所以不需要使用填充字符。
因此，形成 3 组，分别是 "abc"、"def" 和 "ghi" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcdefghij", k = 3, fill = "x"
<strong>输出：</strong>["abc","def","ghi","jxx"]
<strong>解释：</strong>
与前一个例子类似，形成前三组 "abc"、"def" 和 "ghi" 。
对于最后一组，字符串中仅剩下字符 'j' 可以用。为了补全这一组，使用填充字符 'x' 两次。
因此，形成 4 组，分别是 "abc"、"def"、"ghi" 和 "jxx" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>fill</code> 是一个小写英文字母</li>
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
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string sub;
        int i = 0;
        for (auto& c : s) {
            sub += c;
            i = (i + 1) % k;
            if (i == 0) {
                ans.push_back(sub);
                sub = "";
            }
        }
        while (i != 0) {
            sub += fill;
            i = (i + 1) % k;
        }
        if (sub != "") {
            ans.push_back(sub);
        }
        return ans;
    }
};
```




